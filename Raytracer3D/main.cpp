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
    
    int files = 40;
    /*
    //Simulation 1 Rotaton 400m
    Point3D p = Point3D(400, 0, 0);
    double angle = 0;
    
    for(int i = 0; i <= files; i++){
        
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_200m/rotate_degs_400m/rx_" + std::to_string(angle)+ "deg.csv";
        Scene s(p.x(),p.y(),receiver_file);
        std::cout << "***Starting New Transmitter Position ***" << '\n';
        std::cout << "X_position: " << p.x() << "Y_position: " << p.y() <<'\n';
        s.trace_scene(2000);
        p.rotate_Z(2*M_PI/files);
        angle = angle + 2*M_PI/files;
    }
    
    //Simulation 2 Rotation 200m
    p = Point3D(200, 0, 0);
    angle = 0;
    
    for(int i = 0; i <= files; i++){
        
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_200m/rotate_degs_200m/rx_" + std::to_string(angle)+ "deg.csv";
        Scene s(p.x(),p.y(),receiver_file);
        std::cout << "***Starting New Transmitter Position ***" << '\n';
        std::cout << "X_position: " << p.x() << "Y_position: " << p.y() <<'\n';
        s.trace_scene(2000);
        p.rotate_Z(2*M_PI/files);
        angle = angle + 2*M_PI/files;
    }
    
    //Simulation 3 Rotation 50m
    p = Point3D(50, 0, 0);
    angle = 0;
    
    for(int i = 0; i <= files; i++){
        
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_200m/rotate_degs_50m/rx_" + std::to_string(angle)+ "deg.csv";
        Scene s(p.x(),p.y(),receiver_file);
        std::cout << "***Starting New Transmitter Position ***" << '\n';
        std::cout << "X_position: " << p.x() << "Y_position: " << p.y() <<'\n';
        s.trace_scene(2000);
        p.rotate_Z(2*M_PI/files);
        angle = angle + 2*M_PI/files;
    }
    */
    
    //Simulation 4 Range 45deg
    std::cout << "Simulation 4 Range 45deg" << '\n';
    
    double x = 700;
    double y = 700;
    double update = std::abs(x)/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        double r = std::sqrt((std::pow(x,2)+std::pow(y,2)));
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_500m/data_range_45deg/rx_" + std::to_string(r)+ "m_45deg.csv";
        Scene s(x,y,receiver_file);
        std::cout << "***Starting New Transmitter Position ***" << '\n';
        std::cout << "X_position: " << x << "Y_position: " << y <<'\n';
        s.trace_scene(2000);
        x = x - update;
        y = y - update;
        
        time = clock() - time;
        double time_left_sec = ((files - i - 1)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S4: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S4: " << time_left_sec/3600 << " hrs" << '\n';
        }
        
    }
    
    //Simulation 5 Range 135deg
    std::cout << "Simulation 5 Range 135deg" << '\n';
    
    x = -700;
    y = 700;
    update = std::abs(x)/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        double r = std::sqrt((std::pow(x,2)+std::pow(y,2)));
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_500m/data_range_135deg/rx_" + std::to_string(r)+ "m_135deg.csv";
        Scene s(x,y,receiver_file);
        std::cout << "***Starting New Transmitter Position ***" << '\n';
        std::cout << "X_position: " << x << "Y_position: " << y <<'\n';
        s.trace_scene(2000);
        x = x + update;
        y = y - update;
        
        time = clock() - time;
        double time_left_sec = ((files - i - 1)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S5: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S5: " << time_left_sec/3600 << " hrs" << '\n';
        }
    }
    
    //Simulation 6 Range 225deg
    std::cout << "Simulation 6 Range 225deg" << '\n';
    
    x = -700;
    y = -700;
    update = std::abs(x)/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        double r = std::sqrt((std::pow(x,2)+std::pow(y,2)));
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_500m/data_range_225deg/rx_" + std::to_string(r)+ "m_225deg.csv";
        Scene s(x,y,receiver_file);
        std::cout << "***Starting New Transmitter Position ***" << '\n';
        std::cout << "X_position: " << x << "Y_position: " << y <<'\n';
        s.trace_scene(2000);
        x = x + update;
        y = y + update;
        
        time = clock() - time;
        double time_left_sec = ((files - i - 1)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S6: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S6: " << time_left_sec/3600 << " hrs" << '\n';
        }
    }
    
    //Simulation 7 Range 315deg
    std::cout << "Simulation 7 Range 315deg" << '\n';
    
    x = 700;
    y = -700;
    update = std::abs(x)/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        double r = std::sqrt((std::pow(x,2)+std::pow(y,2)));
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_500m/data_range_315deg/rx_" + std::to_string(r)+ "m_315deg.csv";
        Scene s(x,y,receiver_file);
        std::cout << "***Starting New Transmitter Position ***" << '\n';
        std::cout << "X_position: " << x << "Y_position: " << y <<'\n';
        s.trace_scene(2000);
        x = x - update;
        y = y + update;
        
        time = clock() - time;
        double time_left_sec = ((files - i - 1)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S7: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S7: " << time_left_sec/3600 << " hrs" << '\n';
        }
    }
    
    //Simulation 8 Range only x values
    std::cout << "Simulation 8 Range only x values" << '\n';
    
    x = 700;
    y = 0;
    update = std::abs(x)/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_500m/data_range_x/rx_" + std::to_string(x)+ "m_x.csv";
        Scene s(x,y,receiver_file);
        std::cout << "***Starting New Transmitter Position ***" << '\n';
        std::cout << "X_position: " << x << "Y_position: " << y <<'\n';
        s.trace_scene(2000);
        x = x - update*2; //700 to -700
        
        time = clock() - time;
        double time_left_sec = ((files - i - 1)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S8: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S8: " << time_left_sec/3600 << " hrs" << '\n';
        }
    }
    
    //Simulation 9 Range only y values
    std::cout << "Simulation 9 Range only x values" << '\n';
    
    x = 0;
    y = 700;
    update = std::abs(y)/files;
    
    for(int i = 0; i <= files; i++){
        clock_t time = clock();
        std::cout << "File number: " << i <<'\n';
        
        std::string receiver_file = "/Users/tschucker/Desktop/Thesis_data/Receiver_Off_Axis_7m/Altitude_500m/data_range_y/rx_" + std::to_string(y)+ "m_y.csv";
        Scene s(x,y,receiver_file);
        std::cout << "***Starting New Transmitter Position ***" << '\n';
        std::cout << "X_position: " << x << "Y_position: " << y <<'\n';
        s.trace_scene(2000);
        y = y - update*2; //700 to -700
        
        time = clock() - time;
        double time_left_sec = ((files - i - 1)*time)/CLOCKS_PER_SEC;
        if (time_left_sec > 86400) {
            std::cout << "Time Remaining S9: " << time_left_sec/86400 << " days" << '\n';
        }
        else {
            std::cout << "Time Remaining S9: " << time_left_sec/3600 << " hrs" << '\n';
        }
    }
    
    return 0;
}
