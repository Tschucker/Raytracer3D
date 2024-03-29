//
//  Scene.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 2/25/16.
//  Copyright © 2016 BWAC. All rights reserved.
//

#include "Scene.hpp"
#include <time.h>

Scene::Scene()
{
    //create all objects for the scene
    
    //default rotor with id=0, num_blades=1, RPM=350, Height=100m, pitch=0, blade_length=7.5m, rib_count=10.
    rotor = Rotor(0, 2, 500, 100, 0, 7.5, 10);
    
    //default receiver with id=0, Bandwidth=1Mhz, location= 2m below rotor height;
    receiver = Receiver(0, 2000, 1000000000, Point3D(0, 7, rotor.get_height() - .5), .25, "/Users/tschucker/xcode projects/Raytracer3D/rx.csv", "/Users/tschucker/xcode projects/Raytracer3D/dop.csv");
    
    //default transmitter with id=0, frequency=1Ghz, power=10?, location(0,100,0)
}

Scene::Scene(double rx_x, double rx_y, double rx_z, double Bandwidth, double rx_fc, double tx_x, double tx_y, double tx_fc, double tx_power, int num_blades, double RPM, double altitude, double pitch, double blade_length, int num_ribs, const std::string &filename)
{
    //create all objects for the scene
    
    rotor = Rotor(0, num_blades, RPM, altitude, pitch, blade_length, num_ribs);
    
    receiver = Receiver(0, Bandwidth, rx_fc, Point3D(rx_x, rx_y, rotor.get_height() - rx_z), .25, filename, "/Users/tschucker/xcode projects/Raytracer3D/dop.csv");
    std::ofstream myfile;
    myfile.open (filename, std::ios_base::app);
    myfile << altitude << "," << tx_x << "," << tx_y << "," << std::sqrt(tx_x*tx_x + tx_y*tx_y) << "," << std::atan(altitude/std::sqrt(tx_x*tx_x + tx_y*tx_y)) << "," << std::atan(tx_y/tx_x) << ",";
    myfile.close();
    
    transmitters.push_back(Transmitter(0, tx_fc, tx_power, Point3D(tx_x,tx_y,0), std::pow((blade_length + 0.5), 2)));
}

//traces the scene with # of rays per frame.
void Scene::trace_scene(int num_rays)
{
    //calc scene update params for each frame.
    double update_angle = 2*M_PI * (rotor.get_RPM()/60) * (1/receiver.get_sampling_rate());
    
    //calc # of frames (half)
    int number_of_frames = (2*M_PI)/update_angle ;
    
    //std::cout << "update angle: " << update_angle << '\n';
    std::cout << "number of frames: " << number_of_frames << '\n';
    
    update((M_PI/3));
    
    //iterate over the frames
    for (int i = 0; i < number_of_frames; i++) {
        //trace
        /*
        std::cout << "Frame: " << i << '\n';
        double d_i = i;
        double d_number_of_frames = number_of_frames;
        double percent = (d_i/d_number_of_frames)*100;
        clock_t time = clock();
        */
        
        for (int j = 0; j < num_rays; j++) {
            for(int k = 0; k < transmitters.size(); k++){
                Ray3D test_ray = transmitters[k].makeRay_disk(rotor.get_height());
                double hitDistance;
                Vector3D hitNormal;
                Point3D hitPoint;
            
                //check collisions
                //line of sight
                
                if (receiver.get_Boundary().hit(test_ray, hitDistance, hitNormal, hitPoint)) {
                    //add to receiver data
                    test_ray.power = getDistancePower(test_ray.frequency, test_ray.power, hitDistance);
                    receiver.save_ray_toFrame(test_ray);
                }
                
                else if (rotor.hit(test_ray, hitDistance, hitNormal, hitPoint)) {
                    //create new ray that has been doppler shifted and check receiver.
                    trace_vect(test_ray, hitDistance, hitNormal, hitPoint);
                }
            
                else{
                    test_ray.~Ray3D();
                }
            }
        }
        /*
        std::cout << "Percent Complete: " << percent << "%" << '\n';
        time = clock() - time;
        double time_left_sec = ((number_of_frames - i - 1)*time)/CLOCKS_PER_SEC;
        std::cout << "Time Remaining: " << time_left_sec/60 << " mins or " << time_left_sec/3600 << " hrs or " << time_left_sec/86400 << " days" << '\n';
        */
        
        //aggrigate data and save to samples file.
        receiver.save_to_file();
        
        //update scene
        update(update_angle);
    }
}

//recursive method
void Scene::trace_vect(Ray3D &test_ray, double &hitDistance, Vector3D &hitNormal, Point3D &hitPoint)
{
    //determine reflection make sure is a vector
    Vector3D reflection = -test_ray.direction + (2 * hitNormal) * (test_ray.direction * hitNormal);
    
    //create new ray to trace.
    test_ray.power = getDistancePower(test_ray.frequency, test_ray.power, hitDistance);
    test_ray.frequency = getDoppler(test_ray, hitNormal, hitPoint, rotor.get_RPM());
    test_ray.origin = hitPoint;
    test_ray.direction = reflection;
    test_ray.distance = test_ray.distance + hitDistance;
    
    //check for hit on recever (return)
    if (receiver.get_Boundary().hit(test_ray, hitDistance, hitNormal, hitPoint)) {
        test_ray.power = getDistancePower(test_ray.frequency, test_ray.power, hitDistance);
        receiver.save_ray_toFrame(test_ray);
        return;
    }
    
    //else return
    else {
        //determine specular reflection.
        Vector3D spec(test_ray.origin - receiver.center);
        double angle = std::acos(test_ray.direction.normalized()*spec.normalized());
        double power = 0;
        
        
        if (angle < M_PI/2)
        {
            power = test_ray.power*std::pow(test_ray.direction.normalized()*spec.normalized(), 2);
            
        }
        else
        {
            //power = test_ray.power*std::pow(test_ray.direction.normalized()*spec.normalized(), 10);
            power = 0;
            
        }
        
        
        Ray3D spec_ray(test_ray.origin, spec, power, test_ray.frequency, test_ray.distance + test_ray.origin.distance(receiver.center));
        spec_ray.power = getDistancePower(spec_ray.frequency, spec_ray.power, test_ray.origin.distance(receiver.center));
        receiver.save_ray_toFrame(spec_ray);
        return;
    }
}

//updates the scene.
void Scene::update(double angle)
{
    rotor.rotate(angle);
}

Rotor Scene::get_rotor(){
    return rotor;
}

Transmitter Scene::get_transmitter(){
    return transmitter;
}

Receiver Scene::get_receiver(){
    return receiver;
}