//
//  Rotor.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Defines Helicopter rotor, including blades, speed, pitch, lenght, resolution.

#include "Rotor.hpp"

#define M_PI 3.14159265358979323846

Rotor::Rotor()
{
    
}

Rotor::Rotor(const int id, const int num_blades, const double RPM, const double height, const double constant_pitch,
             const double blade_length, const int Rib_count) :
    id(id), num_blades(num_blades), RPM(RPM), height(height), constant_pitch(constant_pitch), blade_length(blade_length),
    Rib_count(Rib_count)
{
    //create full rotor head using blade surface....
    const std::string rib_file = "/Users/tschucker/xcode projects/TestBlade/TestBlade/rib.txt";
    const Rib rib_origin(0,rib_file);
    
    double separation_dist = (2*M_PI)/num_blades;
    
    for (int i = 0; i < num_blades; i++) {
        Blades.push_back(Blade_surface(i, blade_length, Rib_count,rib_origin));
        Blades[i].pitch_surface_X(constant_pitch);
        Blades[i].rotate_surface_Z(separation_dist*i);
        Blades[i].height_surface_Z(height);
    }
    
}

void Rotor::rotate(const double angle){
    for (int i = 0; i < num_blades; i++) {
        Blades[i].rotate_surface_Z(angle);
    }
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

std::vector<Blade_surface> Rotor::get_Blades(){
    return Blades;
}

bool Rotor::hit(const Ray3D &ray, double &hitDistance, Vector3D &hitNormal, Point3D &hitPoint)
{
    //iterate through blades and bounding boxes and return hit on triangle in mesh.
    for (int i = 0; i < Blades.size(); i++) {
        //check bounding box
        if(Blades[i].getBox().hit(ray, hitPoint))
        {
            if(Blades[i].hit(ray, hitDistance, hitNormal, hitPoint))
            {
                std::cout << "hit Rotor" <<'\n';
                return true;
            }
        }
    }
    
    return false;
}

