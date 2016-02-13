//
//  Sphere.hpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Creates sphere object to determine hits on Receiver and to generate
//Rays from the Transmitter.

#ifndef Sphere_hpp
#define Sphere_hpp

#include <stdio.h>
#include <vector>
#include "Point3d.hpp"
#include "Ray3d.hpp"

class Sphere
{
public:
    double radius;
    Point3D center;
    int num_points;
    
    Sphere();
    explicit Sphere(const double radius, const Point3D& center);
    
    bool hit(const Ray3D& ray) const;
    
private:
    
};


#endif /* Sphere_hpp */
