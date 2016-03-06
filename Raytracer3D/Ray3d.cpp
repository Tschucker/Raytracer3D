//
//  Ray3d.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Creates an RF ray in 3d using an origin and Direction.

#include "Ray3d.hpp"
#include <iostream>

Ray3D::Ray3D() :
origin(0, 0, 0), direction(0, 0, .5), power(1.0), frequency(0.0)
{
}

Ray3D::Ray3D(const Point3D& origin, const Vector3D& direction, const double power,
             const double frequency) :
origin(origin), direction(direction), power(power), frequency(frequency)
{
}

Ray3D::~Ray3D(){
    //std::cout << "ray distruct:" << '\n';
}
