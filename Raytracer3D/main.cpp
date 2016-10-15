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
    std::cout << "Raytracer3D Simulation Begin!\n";
    
    //--------------------------------------------------------------------------------------------------------------------------------------

    //inital variables for use in simulations below change parameters there
    
    //--------------------------------------------------------------------------------------------------------------------------------------

    int files = 1;

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
    double RPM = 250;
    double altitude = 200;
    double blade_length = 7.5;
    double pitch = 0;
    int num_ribs = 10;
    
    double update = 0;
    double angle = 0;
    
    double r;
    //--------------------------------------------------------------------------------------------------------------------------------------
    
    //Simulations
    
    //--------------------------------------------------------------------------------------------------------------------------------------

    
    
    //sim 1 variable azimuth angle at tx range pitch
    std::cout << "Simulation 1 azimuth pitch" << '\n';
    
    // setup wanted start conditions and updating parmaters
    files = 10;
    tx_x = 200;
    tx_y = 0;
    pitch = -0.1309;
    Point3D p(tx_x, tx_y, 0);
    update = (2*M_PI)/files;
    angle = 0;
    
    //Run Simulation
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_200m/bistatic_azimuth_45_pitch/rx_test_Bistatic_dop" + std::to_string(angle) + "rad.csv";
        
        Scene s(rx_x, rx_y, rx_z, Bandwidth, rx_fc, p.x(), p.y(), tx_fc, tx_power, num_blades, RPM, altitude, pitch, blade_length, num_ribs,receiver_file);
        
        s.trace_scene(2000);
        
        //update
        angle = angle + update;
        p.rotate_Z(update);
        
        time = clock() - time;
        double time_left_sec = ((files - i)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S1: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S1: " << time_left_sec/3600 << " hrs" << '\n';
        }
        
    }
    
    /*
    //sim 2 variable range 0deg
    std::cout << "Simulation 2 range 0 deg" << '\n';
    files = 0;
    tx_x = 200;
    tx_y = 0;
    Bandwidth = 2000;
    RPM = 250;
    update = tx_x/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_200m//rx_" + std::to_string(tx_x) + "m_0deg.csv";
        
        Scene s(rx_x, rx_y, rx_z, Bandwidth, rx_fc, tx_x, tx_y, tx_fc, tx_power, num_blades, RPM, altitude, pitch, blade_length, num_ribs,receiver_file);
        
        s.trace_scene(2000);
        
        //update
        tx_x = tx_x - update;
        
        time = clock() - time;
        double time_left_sec = ((files - i)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S2: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S2: " << time_left_sec/3600 << " hrs" << '\n';
        }
        
    }
    
    
    //sim 3 variable range 45deg
    std::cout << "Simulation 3 range 45 deg" << '\n';
    files = 10;
    tx_x = 400;
    tx_y = 400;
    update = tx_x/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        r = std::sqrt(tx_x*tx_x + tx_y*tx_y);
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Centered/Altitude_200m/data_range_45deg/rx_" + std::to_string(r) + "m_45deg.csv";
        
        Scene s(rx_x, rx_y, rx_z, Bandwidth, rx_fc, tx_x, tx_y, tx_fc, tx_power, num_blades, RPM, altitude, pitch, blade_length, num_ribs,receiver_file);
        
        s.trace_scene(2000);
        
        //update
        tx_x = tx_x - update;
        tx_y = tx_y - update;
        
        time = clock() - time;
        double time_left_sec = ((files - i)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S3: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S3: " << time_left_sec/3600 << " hrs" << '\n';
        }
        
    }
    
    //sim 4 variable range 90deg
    std::cout << "Simulation 4 range 90 deg" << '\n';
    files = 10;
    tx_x = 0;
    tx_y = 600;
    update = tx_y/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_200m/bistatic_range_90deg/rx_" + std::to_string(tx_y) + "m_90deg.csv";
        
        Scene s(rx_x, rx_y, rx_z, Bandwidth, rx_fc, tx_x, tx_y, tx_fc, tx_power, num_blades, RPM, altitude, pitch, blade_length, num_ribs,receiver_file);
        
        s.trace_scene(2000);
        
        //update
        tx_y = tx_y - update;
        
        time = clock() - time;
        double time_left_sec = ((files - i)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S4: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S4: " << time_left_sec/3600 << " hrs" << '\n';
        }
        
    }
    
    
    //sim 5 variable range 135deg
    std::cout << "Simulation 5 range 135 deg" << '\n';
    files = 10;
    tx_x = -400;
    tx_y = 400;
    update = std::abs(tx_x)/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        r = std::sqrt(tx_x*tx_x + tx_y*tx_y);
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Centered/Altitude_200m/data_range_135deg/rx_" + std::to_string(r) + "m_135deg.csv";
        
        Scene s(rx_x, rx_y, rx_z, Bandwidth, rx_fc, tx_x, tx_y, tx_fc, tx_power, num_blades, RPM, altitude, pitch, blade_length, num_ribs,receiver_file);
        
        s.trace_scene(2000);
        
        //update
        tx_x = tx_x + update;
        tx_y = tx_y - update;
        
        time = clock() - time;
        double time_left_sec = ((files - i)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S5: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S5: " << time_left_sec/3600 << " hrs" << '\n';
        }
        
    }
    
    
    //sim 6 variable range 180deg
    std::cout << "Simulation 6 range 180 deg" << '\n';
    files = 20;
    tx_x = -1000;
    tx_y = 0;
    update = std::abs(tx_x)/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_200m/data_rangeFar_180deg/rx_" + std::to_string(tx_x) + "m_180deg.csv";
        
        Scene s(rx_x, rx_y, rx_z, Bandwidth, rx_fc, tx_x, tx_y, tx_fc, tx_power, num_blades, RPM, altitude, pitch, blade_length, num_ribs,receiver_file);
        
        s.trace_scene(2000);
        
        //update
        tx_x = tx_x + update;
        
        time = clock() - time;
        double time_left_sec = ((files - i)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S6: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S6: " << time_left_sec/3600 << " hrs" << '\n';
        }
        
    }
    
    
    //sim 7 variable range 225deg
    std::cout << "Simulation 7 range 225 deg" << '\n';
    files = 10;
    tx_x = -400;
    tx_y = -400;
    update = std::abs(tx_x)/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        r = std::sqrt(tx_x*tx_x + tx_y*tx_y);
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Centered/Altitude_200m/data_range_225deg/rx_" + std::to_string(r) + "m_225deg.csv";
        
        Scene s(rx_x, rx_y, rx_z, Bandwidth, rx_fc, tx_x, tx_y, tx_fc, tx_power, num_blades, RPM, altitude, pitch, blade_length, num_ribs,receiver_file);
        
        s.trace_scene(2000);
        
        //update
        tx_x = tx_x + update;
        tx_y = tx_y + update;
        
        time = clock() - time;
        double time_left_sec = ((files - i)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S7: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S7: " << time_left_sec/3600 << " hrs" << '\n';
        }
        
    }
    
    //sim 8 variable range 270deg
    std::cout << "Simulation 8 range 270 deg" << '\n';
    files = 10;
    tx_x = 0;
    tx_y = -600;
    update = std::abs(tx_y)/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_200m/bistatic_range_270deg/rx_" + std::to_string(tx_y) + "m_270deg.csv";
        
        Scene s(rx_x, rx_y, rx_z, Bandwidth, rx_fc, tx_x, tx_y, tx_fc, tx_power, num_blades, RPM, altitude, pitch, blade_length, num_ribs,receiver_file);
        
        s.trace_scene(2000);
        
        //update
        tx_y = tx_y + update;
        
        time = clock() - time;
        double time_left_sec = ((files - i)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S8: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S8: " << time_left_sec/3600 << " hrs" << '\n';
        }
        
    }
    
    //sim 9 variable range 315deg
    std::cout << "Simulation 9 range 315 deg" << '\n';
    files = 10;
    tx_x = 400;
    tx_y = -400;
    update = std::abs(tx_x)/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        r = std::sqrt(tx_x*tx_x + tx_y*tx_y);
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Centered/Altitude_200m/data_range_315deg/rx_" + std::to_string(r) + "m_315deg.csv";
        
        Scene s(rx_x, rx_y, rx_z, Bandwidth, rx_fc, tx_x, tx_y, tx_fc, tx_power, num_blades, RPM, altitude, pitch, blade_length, num_ribs,receiver_file);
        
        s.trace_scene(2000);
        
        //update
        tx_x = tx_x - update;
        tx_y = tx_y + update;
        
        time = clock() - time;
        double time_left_sec = ((files - i)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S9: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S9: " << time_left_sec/3600 << " hrs" << '\n';
        }
        
    }
    */
    
    return 0;
}
