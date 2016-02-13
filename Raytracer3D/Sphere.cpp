//
//  Sphere.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Creates sphere object to determine hits on Receiver and to generate
//Rays from the Transmitter.

#include "Sphere.hpp"

Sphere::Sphere()
{
    
}

Sphere::Sphere(const double radius, const Point3D& center) :
radius(radius), center(center)
{
    
}

bool Sphere::hit(const Ray3D &ray) const
{
    //TODO math for hit on the sphere
    return true;
}


