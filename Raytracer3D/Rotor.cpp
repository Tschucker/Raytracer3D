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

Rotor::Rotor(int id, const int num_blades, const double RPM, const double height, const double constant_pitch) :
    id(id), num_blades(num_blades), RPM(RPM), height(height)
{
    //create full rotor head using blade surface....
}

double Rotor::get_RPM(){
    return RPM;
}

double Rotor::get_height(){
    return height;
}

int Rotor::get_num_blades(){
    return num_blades;
}

double Rotor::get_constant_pitch(){
    return constant_pitch;
}