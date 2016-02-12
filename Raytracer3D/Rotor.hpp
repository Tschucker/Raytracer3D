//
//  Rotor.hpp
//  TestBlade
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
    double RPM;
    int num_blades;
    
    double height;
    Point3D axis_rotation; //use height for where the point should be. use 0,0,height for ease of use
    
    
};


#endif /* Rotor_hpp */
