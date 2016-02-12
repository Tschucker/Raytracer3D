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
    
    Bounding_box();
    explicit Bounding_box(Blade_surface& Bsurface);
    
private:
    int id;
    Point3D p1;
    Point3D p2;
    
};

#endif /* Bounding_box_hpp */
