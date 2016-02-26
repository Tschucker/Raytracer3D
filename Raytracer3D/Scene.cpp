//
//  Scene.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 2/25/16.
//  Copyright © 2016 BWAC. All rights reserved.
//

#include "Scene.hpp"

Scene::Scene()
{
    //create all objects for the scene
    
    //default rotor with id=0, num_blades=1, RPM=350, Height=100m, pitch=0, blade_length=5m, rib_count=10.
    rotor = Rotor(0, 1, 350, 100, 0, 5, 10);
    
    //default transmitter with id=0, frequency=1Ghz, power=10?, location(0,100,0);
    transmitter = Transmitter(0, 1000000000, 10, Point3D(0,100,0));
    
    //default receiver with id=0, Bandwidth=1Mhz, location= .5m below rotor height;
    receiver = Receiver(0, 1000000, 1000000000, Point3D(0, 0, rotor.get_height() - .5), .1);
    
}

//traces the scene with # of rays per frame.
void Scene::trace(int num_rays)
{
    //calc scene update params for each frame.
    double update_angle = 2*M_PI * (rotor.get_RPM()/60) * (1/receiver.get_sampling_rate());
    
    //calc # of frames
    int number_of_frames = (2*M_PI)/update_angle;
    
    std::cout << "test: " << rotor.get_RPM() << '\n';
    
    std::cout << "update angle: " << update_angle << '\n';
    std::cout << "number of frames: " << number_of_frames << '\n';
    
    //iterate over the frames
        //trace
    
        //collect data
        //aggrigate data and save to samples file.
        //update scene
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