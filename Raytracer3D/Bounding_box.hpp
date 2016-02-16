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
    explicit Bounding_box(const Blade_surface& Bsurface);
    
    
    bool hit(const Ray3D& ray, Point3D& hit_point) const;
    bool hit(const Ray3D& ray) const;
    
    
private:
    
    
};

#endif /* Bounding_box_hpp */
