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
    ~Triangle();
    explicit Triangle(Point3D &v0, Point3D &v1, Point3D &v2);
    
    bool hit(const Ray3D& ray, double& hitDistance, Vector3D& hitNormal, Point3D& hitPoint) const;
    bool hitNoCull(const Ray3D& ray, double& hitDistance, Vector3D& hitNormal, Point3D& hitPoint) const;
    //Bounding_box getBoundingBox() const;
    
    bool operator==(Triangle& Tri) ;
    
    Point3D getVertex0();
    Point3D getVertex1();
    Point3D getVertex2();
    
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

inline bool Triangle::operator==(Triangle& Tri)
{
    if((getVertex0()==Tri.getVertex0())&&(getVertex1()==Tri.getVertex1())&&(getVertex2()==Tri.getVertex2())){
        return true;
    }
    else{
        return false;
    }
}


#endif /* Triangle_hpp */
