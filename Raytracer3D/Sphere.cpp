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
#include <cmath>
#include <iostream>

#define EPSILON 0.0000001

Sphere::Sphere()
{
    
}

Sphere::Sphere(const double radius, const Point3D& center) :
radius(radius), center(center)
{
    
}

bool Sphere::hit(const Ray3D &ray, double& hitDistance, Vector3D& hitNormal, Point3D& hitPoint) const
{
    //Math for hit on the sphere.
    double t;
    Vector3D temp(ray.origin - center);
    double a = ray.direction * ray.direction;
    double b = 2 * (ray.direction * temp);
    double c = (temp * temp) - (radius * radius);
    double disc = (b * b) - (4 * a * c);
    
    if (disc < 0) {
        return false;
    }
    else {
        double e = std::sqrt(disc);
        double denominator = 2 * a;
        
        t = (-b - e)/denominator; //small root
        
        if (t > EPSILON) {
            //tmin = t;
            hitNormal = (temp + (t * ray.direction));
            hitPoint = ray.origin + t * ray.direction;
            return true;
        }
        
        t = (-b + e)/denominator; //large root
        
        if (t > EPSILON) {
            //tmin = t;
            hitNormal = (temp + (t * ray.direction));
            hitPoint = ray.origin + t * ray.direction;
            return true;
        }
        
    }
    return false;
}


