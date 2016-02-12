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

#include <sstream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(int argc, char **argv) {
    // insert code here... for testing
    std::cout << "Hello, World!\n";
    const std::string test = "/Users/tschucker/xcode projects/TestBlade/TestBlade/rib.txt";
    Rib rib_one(0,test);
    
    Blade_surface Bsurface(1,5,10,rib_one);
    std::cout << "delta_l: " << Bsurface.delta_l << '\n';
    
    /*
    for (int i = 0; i < Bsurface.getRibs().size(); i++) {
        std::cout << Bsurface.getRibs()[i].getRibPoints()[0].x() << '\n';
        std::cout << Bsurface.getRibs()[i].getRibPoints()[0].y() << '\n';
        std::cout << Bsurface.getRibs()[i].getRibPoints()[0].z() << '\n';
        std::cout << '\n';
    }
    
    Bsurface.rotate_surface_Z(M_PI);
    
    for (int i = 0; i < Bsurface.getRibs().size(); i++) {
        std::cout << Bsurface.getRibs()[i].getRibPoints()[0].x() << '\n';
        std::cout << Bsurface.getRibs()[i].getRibPoints()[0].y() << '\n';
        std::cout << Bsurface.getRibs()[i].getRibPoints()[0].z() << '\n';
        std::cout << '\n';
    }
    */
    
    std::cout << Bsurface.getSurface().size()<< '\n';
    Transmitter tr;
    for (int i = 0; i <20; i++) {
        tr.makeRay();
    }
    
    return 0;
}
