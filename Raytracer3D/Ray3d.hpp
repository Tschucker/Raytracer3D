//
//  Ray3d.hpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Creates an RF ray in 3d using an origin and Direction.

#ifndef Ray3d_hpp
#define Ray3d_hpp

#include <stdio.h>
#include "Point3d.hpp"

class Ray3D
{
public:
    Point3D origin;
    Vector3D direction;
    double power;
    double frequency;
    //Color color;
    
    Ray3D();
    explicit Ray3D(const Point3D& origin, const Vector3D& direction, const double power = 1.0,
                   const double frequency = 0.0); //const Color color = Color(255, 255, 255));
};


#endif /* Ray3d_hpp */
