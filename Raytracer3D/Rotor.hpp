//
//  Rotor.hpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Defines Helicopter rotor, including blades, speed, pitch, lenght, resolution.

#ifndef Rotor_hpp
#define Rotor_hpp

#include <stdio.h>
#include "Blade_surface.hpp"

class Rotor
{
public:
    int id;
    
    double get_RPM();
    int get_num_blades();
    double get_height();
    double get_constant_pitch();
    double get_Rib_count();
    double get_blade_length();
    std::vector<Blade_surface> get_Blades();
    
    void rotate(const double angle);
    
    Rotor();
    Rotor(const int id, const int num_blades, const double RPM, const double height, const double constant_pitch,
          const double blade_length, const int Rib_count);
        
private:
    double RPM;
    int num_blades;
    double height;
    double constant_pitch;
    double blade_length;
    int Rib_count;
    std::vector<Blade_surface> Blades;
};


#endif /* Rotor_hpp */
