//
//  main.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

#include <iostream>
#include "Rib.hpp"
#include "Blade_surface.hpp"
#include "Transmitter.hpp"
#include "Sphere.hpp"
#include "Bounding_box.hpp"
#include "Scene.hpp"
#include "Triangle.hpp"

#include <sstream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(int argc, char **argv) {
    // insert code here... for testing
    std::cout << "Raytracer3D main test!\n";
    
    int files = 10;

    double rx_x = 0;
    double rx_y = 7;
    double rx_z = 2;
    double Bandwidth = 2000;
    double rx_fc = 1000000000;
    
    double tx_x = 100;
    double tx_y = 100;
    double tx_fc = 1000000000;
    double tx_power = 4000;
    
    int num_blades = 2;
    double RPM = 500;
    double altitude = 200;
    double blade_length = 7.5;
    double pitch = 0;
    int num_ribs = 10;
    
    /*
    //sim 1 var pitch tx 45 deg
    std::cout << "Simulation 1 var:pitch tx:45deg" << '\n';
    tx_x = 100;
    tx_y = 100;
    pitch = -.2618; //variable
    
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_200m/data_pitch_max15deg_45deg/rx_" + std::to_string(pitch)+ "pitch_r.csv";
        
        Scene s(rx_x, rx_y, rx_z, Bandwidth, rx_fc, tx_x, tx_y, tx_fc, tx_power, num_blades, RPM, altitude, pitch, blade_length, num_ribs,receiver_file);
        
        s.trace_scene(2000);
        pitch = pitch + update;
        
        time = clock() - time;
        double time_left_sec = ((files - i - 1)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S4: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S4: " << time_left_sec/3600 << " hrs" << '\n';
        }
        
    }
    
    //sim 2 var pitch tx 225 deg
    std::cout << "Simulation 2 var:pitch tx:225deg" << '\n';
    tx_x = -100;
    tx_y = -100;
    pitch = -.2618; //variable
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_200m/data_pitch_max15deg_225deg/rx_" + std::to_string(pitch)+ "pitch_r.csv";
        
        Scene s(rx_x, rx_y, rx_z, Bandwidth, rx_fc, tx_x, tx_y, tx_fc, tx_power, num_blades, RPM, altitude, pitch, blade_length, num_ribs,receiver_file);
        
        s.trace_scene(2000);
        pitch = pitch + update;
        
        time = clock() - time;
        double time_left_sec = ((files - i - 1)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S4: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S4: " << time_left_sec/3600 << " hrs" << '\n';
        }
        
    }
    */
    
    //sim 3 var pitch tx 315 deg
    std::cout << "Simulation 3 var:pitch tx:315deg" << '\n';
    tx_x = 100;
    tx_y = -100;
    pitch = -.2618; //variable
    double update = std::abs(pitch)/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_200m/data_pitch_max15deg_315deg/rx_" + std::to_string(pitch)+ "pitch_r.csv";
        
        Scene s(rx_x, rx_y, rx_z, Bandwidth, rx_fc, tx_x, tx_y, tx_fc, tx_power, num_blades, RPM, altitude, pitch, blade_length, num_ribs,receiver_file);
        
        s.trace_scene(2000);
        pitch = pitch + update;
        
        time = clock() - time;
        double time_left_sec = ((files - i - 1)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S4: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S4: " << time_left_sec/3600 << " hrs" << '\n';
        }
        
    }
    
    return 0;
}
