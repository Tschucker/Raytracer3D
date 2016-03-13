//
//  Scene.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 2/25/16.
//  Copyright © 2016 BWAC. All rights reserved.
//

#include "Scene.hpp"

int bounce = 0;


Scene::Scene()
{
    //create all objects for the scene
    
    //default rotor with id=0, num_blades=1, RPM=350, Height=100m, pitch=0, blade_length=5m, rib_count=10.
    rotor = Rotor(0, 1, 400, 100, 0, 7.5, 20);
    
    //default receiver with id=0, Bandwidth=1Mhz, location= 2m below rotor height;
    receiver = Receiver(0, 5000, 1000000000, Point3D(0, 0, rotor.get_height() - 2), .5, "/Users/tschucker/xcode projects/Raytracer3D/rx.txt");
    
    //default transmitter with id=0, frequency=1Ghz, power=10?, location(0,100,0);
    transmitter = Transmitter(0, 1000000000, 10, Point3D(50,50,0), 5);
    
}

//traces the scene with # of rays per frame.
void Scene::trace_scene(int num_rays)
{
    //calc scene update params for each frame.
    double update_angle = 2*M_PI * (rotor.get_RPM()/60) * (1/receiver.get_sampling_rate());
    
    //calc # of frames
    int number_of_frames = (4*M_PI)/update_angle ;
    
    std::cout << "test: " << rotor.get_RPM() << '\n';
    std::cout << "update angle: " << update_angle << '\n';
    std::cout << "number of frames: " << number_of_frames << '\n';
    
    //iterate over the frames
    for (int i = 0; i < number_of_frames; i++) {
        //trace
        std::cout << "new Frame: " << i << '\n';
        
        for (int j = 0; j < num_rays; j++) {
            Ray3D test_ray = transmitter.makeRay_disk(rotor.get_height());
            double hitDistance;
            Vector3D hitNormal;
            Point3D hitPoint;
            
            //check collisions
            if (receiver.get_Boundary().hit(test_ray, hitDistance, hitNormal, hitPoint)) {
                //add to receiver data
                test_ray.power = getDistancePower(test_ray.frequency, test_ray.power, hitDistance);
                receiver.save_ray_toFrame(test_ray);
                bounce = 0;
                
            }
            
            else if (rotor.hit(test_ray, hitDistance, hitNormal, hitPoint)) {
                //create new ray that has been doppler shifted and check receiver.
                trace_vect(test_ray, hitDistance, hitNormal, hitPoint);
            }
            else{
                test_ray.~Ray3D();
            }
        }
        
        //aggrigate data and save to samples file.
        receiver.save_to_file();
        
        //update scene
        update(update_angle);
    }
    std::cout << "final recived: " << receiver.get_frame_data().size() << '\n';
}

//recursive method
void Scene::trace_vect(Ray3D &test_ray, double &hitDistance, Vector3D &hitNormal, Point3D &hitPoint)
{
    bounce++;
    
    //determine reflection make sure is a vector
    Vector3D reflection = test_ray.direction - (2 * hitNormal) * (test_ray.direction * hitNormal);
    
    //create new ray to trace.
    test_ray.power = getDistancePower(test_ray.frequency, test_ray.power, hitDistance);
    test_ray.origin = hitPoint;
    test_ray.direction = reflection;
    test_ray.frequency = getDoppler(test_ray, hitNormal, hitPoint, rotor.get_RPM());
    test_ray.distance = test_ray.distance + hitDistance;
    
    //check for hit on recever (return)
    if (receiver.get_Boundary().hit(test_ray, hitDistance, hitNormal, hitPoint)) {
        receiver.save_ray_toFrame(test_ray);
        bounce = 0;
        return;
    }
    
    //check for hit on blade? or other object (call trace_vect on new)
    else if (rotor.hit(test_ray, hitDistance, hitNormal, hitPoint)){
        
        //determine specular reflection.
        Vector3D spec(test_ray.origin - receiver.center);
        double angle = std::acos( test_ray.direction.normalized()*spec.normalized());
        if (angle < M_PI/2)
        {
            double power = test_ray.power*std::pow(test_ray.direction.normalized()*spec.normalized(), 2);
            Ray3D spec_ray(test_ray.origin, spec, power, test_ray.frequency, test_ray.distance + test_ray.origin.distance(receiver.center));
            receiver.save_ray_toFrame(spec_ray);
        }
        
        //recursive call of trace vector.
        trace_vect(test_ray, hitDistance, hitNormal, hitPoint);
        
    }
    
    //else return
    else {
        //determine specular reflection.
        Vector3D spec(test_ray.origin - receiver.center);
        double angle = std::acos( test_ray.direction.normalized()*spec.normalized());
        if (angle < M_PI/2)
        {
            double power = test_ray.power*std::pow(test_ray.direction.normalized()*spec.normalized(), 2);
            Ray3D spec_ray(test_ray.origin, spec, power, test_ray.frequency, test_ray.distance + test_ray.origin.distance(receiver.center));
            receiver.save_ray_toFrame(spec_ray);
        }
        
        bounce = 0;
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