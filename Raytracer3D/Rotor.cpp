//
//  Rotor.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Defines Helicopter rotor, including blades, speed, pitch, lenght, resolution.

#include "Rotor.hpp"

Rotor::Rotor()
{
    
}

Rotor::Rotor(int id, int num_blades, double RPM, double height) :
    id(id), num_blades(num_blades), RPM(RPM), height(height)
{
    //create full rotor head using blade surface....
}