//
//  Bounding_box.hpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/23/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

#ifndef Bounding_box_hpp
#define Bounding_box_hpp

#include <stdio.h>
#include "Point3d.hpp"
#include "Blade_surface.hpp"


class Bounding_box
{
public:
    Point3D min_point;
    Point3D max_point;
    
    Bounding_box();
    explicit Bounding_box(Blade_surface& Bsurface);
    //explicit Bounding_box(Point3D& p1, Point3D& p2);
    
    bool hit();
    
private:
    
    
};

#endif /* Bounding_box_hpp */
