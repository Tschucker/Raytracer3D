//
//  Sphere.cpp
//  TestBlade
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

Sphere::Sphere(const double radius, const Point3D& center, const int num_points) :
radius(radius), center(center), num_points(num_points)
{
    
}

Sphere::Sphere(const double radius, const Point3D& center) :
radius(radius), center(center),  num_points(0)
{
    
}

bool Sphere::hit(const Ray3D &ray) const
{
    //TODO math for hit on the sphere
    return true;
}


