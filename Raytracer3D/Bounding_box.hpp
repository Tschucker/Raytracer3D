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
#include "Ray3d.hpp"
#include <vector>


class Bounding_box
{
public:
    Point3D min_point;
    Point3D max_point;
    
    Bounding_box();
    explicit Bounding_box(std::vector<Point3D>& points);
    
    
    bool hit(const Ray3D& ray, Point3D& hit_point) const;
    bool hit(const Ray3D& ray) const;
    
    
private:
    
    
};

#endif /* Bounding_box_hpp */
