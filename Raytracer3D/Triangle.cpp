//
//  Triangle.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//  Eric

//Creates triangle object to detect Ray hits on the Blade surface.

#include "Triangle.hpp"
#include <iostream>

#define EPSILON 0.0000001

Triangle::Triangle() :
v0(0.0, 0.0, 0.0), v1(1.0, 0.0, 0.0), v2(0.0, 1.0, 0.0)
{
    updateNormal();
}

Triangle::Triangle(const Point3D& v0, const Point3D& v1, const Point3D& v2) :
v0(v0), v1(v1), v2(v2)
{
    updateNormal();
}

// Möller-Trumbore TRIANGLE_BACKFACE_CULLING
bool Triangle::hit(const Ray3D& ray, double &hitDistance, Vector3D &hitNormal, Point3D &hitPoint) const
{
    const Vector3D edge1(v1 - v0);
    const Vector3D edge2(v2 - v0);
    
    const Vector3D p(ray.direction ^ edge2);
    
    const double det = edge1 * p;
    
    if (det < EPSILON)
        return false;
    
    const Vector3D t(ray.origin - v0);
    
    const double u = t * p;
    if (u < 0.0 || u > det)
        return false;
    
    const Vector3D q(t ^ edge1);
    
    const double v = ray.direction * q;
    if (v < 0.0 || u + v > det)
        return false;
    
    const double detInv = 1.0 / det;
    
    const double tminTest = (edge2 * q) * detInv;
    if (tminTest < EPSILON)
        return false;
    
    hitDistance = tminTest;
    hitPoint = ray.origin + hitDistance * ray.direction;
    hitNormal = normal;
    
    return true;
}

// Möller-Trumbore
bool Triangle::hitNoCull(const Ray3D& ray, double &hitDistance, Vector3D &hitNormal, Point3D &hitPoint) const
{
    const Vector3D edge1(v1 - v0);
    const Vector3D edge2(v2 - v0);
    
    const Vector3D p(ray.direction ^ edge2);
    
    const double det = edge1 * p;
    
    if (det > -EPSILON && det < EPSILON)
        return false;
    
    const double detInv = 1.0 / det;
    
    const Vector3D t(ray.origin - v0);
    
    const double u = (t * p) * detInv;
    if (u < 0.0 || u > 1.0)
        return false;
    
    const Vector3D q(t ^ edge1);
    
    const double v = (ray.direction * q) * detInv;
    if (v < 0.0 || u + v > 1.0)
        return false;
    
    const double tminTest = (edge2 * q) * detInv;
    if (tminTest < EPSILON)
        return false;
    
    hitDistance = tminTest;
    hitPoint = ray.origin + hitDistance * ray.direction;
    
    // fix hit normal if surface normal extends from opposite side of ray collision
    double d = ray.direction * normal;
    if (d <= 0.0)
        hitNormal = normal;
    else
        hitNormal = -normal;
    
    return true;
}

/*
AABB3D Triangle::getBoundingBox() const
{
    return AABB3D(v0, v1);
}
*/

Point3D Triangle::getVertex0() const
{
    return v0;
}

Point3D Triangle::getVertex1() const
{
    return v1;
}

Point3D Triangle::getVertex2() const
{
    return v2;
}

Vector3D Triangle::getNormal() const
{
    return normal;
}

void Triangle::setNormal(const Vector3D &normal)
{
    this->normal = normal;
}

//had to add swap as a friend function for it to work
void Triangle::flipNormal()
{
    std::swap(v0, v1);
    updateNormal();
}

void Triangle::updateNormal()
{
    const Vector3D edge1(v1 - v0);
    const Vector3D edge2(v2 - v0);
    
    normal = (edge1 ^ edge2).normalized();
}

Point3D Triangle::centroid() const
{
    return Point3D((v0.x() + v1.x() + v2.x()) / 3.0, (v0.y() + v1.y() + v2.y()) / 3.0,
                   (v0.z() + v1.z() + v2.z()) / 3.0);
}

Point3D Triangle::centroidXY() const
{
    return Point3D((v0.x() + v1.x() + v2.x()) / 3.0, (v0.y() + v1.y() + v2.y()) / 3.0, 0.0);
}
