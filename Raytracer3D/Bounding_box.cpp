//
//  Bounding_box.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/23/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

#include "Bounding_box.hpp"

#define EPSILON 0.000001

Bounding_box::Bounding_box(){
    
}

//for axis aligned
Bounding_box::Bounding_box(std::vector<Point3D>& points)
{    
    double x_min = 1000, y_min = 1000, z_min = 1000;
    double x_max = -1000, y_max = -1000, z_max = -1000;
    
    for (int i = 0; i < points.size(); i++) {
        x_min = std::min(x_min, points[i].x());
        y_min = std::min(y_min, points[i].y());
        z_min = std::min(z_min, points[i].z());
        
        x_max = std::max(x_max, points[i].x());
        y_max = std::max(y_max, points[i].y());
        z_max = std::max(z_max, points[i].z());
    }
    Point3D min(x_min, y_min, z_min);
    Point3D max(x_max, y_max, z_max);
    
    min_point = min;
    max_point = max;
    
}

bool Bounding_box::hit(const Ray3D& ray, Point3D& hit_point) const
{
    //Math for hit on axis aligned bounding box.
    double tx_min, ty_min, tz_min;
    double tx_max, ty_max, tz_max;
    
    if (ray.direction.x() >= 0)
    {
        tx_min = (min_point.x() - ray.origin.x()) / ray.direction.x();
        tx_max = (max_point.x() - ray.origin.x()) / ray.direction.x();
    }
    else
    {
        tx_min = (max_point.x() - ray.origin.x()) / ray.direction.x();
        tx_max = (min_point.x() - ray.origin.x()) / ray.direction.x();
    }
    
    if (ray.direction.y() >= 0)
    {
        ty_min = (min_point.y() - ray.origin.y()) / ray.direction.y();
        ty_max = (max_point.y() - ray.origin.y()) / ray.direction.y();
    }
    else
    {
        ty_min = (max_point.y() - ray.origin.y()) / ray.direction.y();
        ty_max = (min_point.y() - ray.origin.y()) / ray.direction.y();
    }
    
    double t0, t1;
    
    // find largest entering t value
    if (tx_min > ty_min)
    {
        t0 = tx_min;
    }
    else
    {
        t0 = ty_min;
    }
    
    // find smallest exiting t value
    if (tx_max < ty_max)
    {
        t1 = tx_max;
    }
    else
    {
        t1 = ty_max;
    }
    
    if (ray.direction.z() != 0.0)
    {
        if (ray.direction.z() > 0.0)
        {
            tz_min = (min_point.z() - ray.origin.z()) / ray.direction.z();
            tz_max = (max_point.z() - ray.origin.z()) / ray.direction.z();
        }
        else
        {
            tz_min = (max_point.z() - ray.origin.z()) / ray.direction.z();
            tz_max = (min_point.z() - ray.origin.z()) / ray.direction.z();
        }
        
        if (tz_min > t0)
        {
            t0 = tz_min;
        }
        
        if (tz_max < t1)
        {
            t1 = tz_max;
        }
    }
    
    if (t0 < t1 && t1 > EPSILON) // condition for a hit
    {
        double tmin;
        if (t0 > EPSILON)
        {
            tmin = t0;  			// ray hits outside surface
        }
        else
        {
            tmin = t1;				// ray hits inside surface
        }
        
        hit_point = ray.origin + tmin * ray.direction;
        
        return true;
    }
    else
        return false;
}

bool Bounding_box::hit(const Ray3D& ray) const
{
    Point3D hit_point;
    return hit(ray, hit_point);
}