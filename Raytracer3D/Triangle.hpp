//
//  Triangle.hpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//  Eric

//Creates triangle object to detect Ray hits on the Blade surface.

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>
#include "Ray3d.hpp"
#include "Point3d.hpp"

class Triangle
{
public:
    Triangle();
    explicit Triangle(const Point3D& v0, const Point3D& v1, const Point3D& v2);
    
    bool hit(const Ray3D& ray, double& hitDistance, Vector3D& hitNormal, Point3D& hitPoint) const;
    bool hitNoCull(const Ray3D& ray, double& hitDistance, Vector3D& hitNormal, Point3D& hitPoint) const;
    //AABB3D getBoundingBox() const;
    
    bool operator==(const Triangle&) const;
    
    Point3D getVertex0() const;
    Point3D getVertex1() const;
    Point3D getVertex2() const;
    
    Vector3D getNormal() const;
    void setNormal(const Vector3D &normal);
    void flipNormal();
    
    Point3D centroid() const;
    Point3D centroidXY() const;
    void updateNormal();
    
private:
    Point3D v0;
    Point3D v1;
    Point3D v2;
    Vector3D normal;
    
};

inline bool Triangle::operator==(const Triangle& Tri) const
{
    if((this->getVertex0()==Tri.getVertex0())&&(this->getVertex1()==Tri.getVertex1())&&(this->getVertex2()==Tri.getVertex2())){
        return true;
    }
    else{
        return false;
    }
}


#endif /* Triangle_hpp */
