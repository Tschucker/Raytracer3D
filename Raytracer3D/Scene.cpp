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
    rotor = Rotor(0, 1, 350, 12, 0, 5, 10);
    
    //default transmitter with id=0, frequency=1Ghz, power=10?, location(0,100,0);
    transmitter = Transmitter(0, 1000000000, 10, Point3D(0,10,0));
    
    //default receiver with id=0, Bandwidth=1Mhz, location= 2m below rotor height;
    receiver = Receiver(0, 1000000, 1000000000, Point3D(0, 0, rotor.get_height() - 2), 1);
    
}

//traces the scene with # of rays per frame.
void Scene::trace_scene(int num_rays)
{
    //calc scene update params for each frame.
    double update_angle = 2*M_PI * (rotor.get_RPM()/60) * (1/receiver.get_sampling_rate());
    
    //calc # of frames
    int number_of_frames = (2*M_PI)/update_angle;
    
    number_of_frames = 1;
    
    std::cout << "test: " << rotor.get_RPM() << '\n';
    
    std::cout << "update angle: " << update_angle << '\n';
    std::cout << "number of frames: " << number_of_frames << '\n';
    
    //iterate over the frames
    for (int i = 0; i < number_of_frames; i++) {
        //trace
        for (int j = 0; j < num_rays; j++) {
            Ray3D test_ray = transmitter.makeRay();
            double hitDistance;
            Vector3D hitNormal;
            Point3D hitPoint;
            //check collisions
            if (receiver.get_Boundary().hit(test_ray, hitDistance, hitNormal, hitPoint)) {
                //add to receiver data
                
                //need to power adjust
                receiver.save_ray_toFrame(test_ray);
                bounce = 0;
                
            }
            
            else if (rotor.hit(test_ray, hitDistance, hitNormal, hitPoint)) {
                //create new ray that has been doppler shifted and check receiver.
                trace_vect(test_ray, hitDistance, hitNormal, hitPoint);
            }
        }
        //collect data
        
        //aggrigate data and save to samples file.
        
        //update scene
        update();
    }
    std::cout << "final recived: " << receiver.get_frame_data().size() << '\n';
}

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
    
    //determine specular reflection?
    
    
    //check for hit on recever (return)
    if (receiver.get_Boundary().hit(test_ray, hitDistance, hitNormal, hitPoint)) {
        receiver.get_frame_data().push_back(test_ray);
        std::cout << "reflected in!"<<'\n';
        bounce = 0;
        return;
    }
    
    //check for hit on blade? or other object (call trace_vect on new)
    else if (rotor.hit(test_ray, hitDistance, hitNormal, hitPoint)){
        trace_vect(test_ray, hitDistance, hitNormal, hitPoint);
        std::cout << "into" << '\n';
    }
    
    //else return
    
    else {
        std::cout << "no reflection bounces: " << bounce <<'\n';
        return;
    }
}

//updates the scene give params not sure yet.
void Scene::update()
{
    
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