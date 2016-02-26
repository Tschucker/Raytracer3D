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
    //Point3D get_axis();
    
    Rotor();
    Rotor(int id, const int num_blades, const double RPM, const double height, const double constant_pitch);
        
private:
    double RPM;
    int num_blades;
    double height;
    double constant_pitch;
    //Point3D axis_rotation; //use height for where the point should be. use 0,0,height for ease of use
};


#endif /* Rotor_hpp */
