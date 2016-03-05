//
//  Point3d.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//  Eric

//Creates 3D point in space.

#include "Point3d.hpp"
#include <cmath>

Point3D::Point3D() :
m_x(0.0), m_y(0.0), m_z(0.0)
{
}

Point3D::Point3D(const double x, const double y, const double z) :
m_x(x), m_y(y), m_z(z)
{
}

Point3D::Point3D(const double y, const double z) :
m_x(0.0), m_y(y), m_z(z)
{
}

double Point3D::distance(const Point3D& p) const
{
    return (std::sqrt((m_x - p.x()) * (m_x - p.x()) + (m_y - p.y()) * (m_y - p.y()) + (m_z - p.z()) * (m_z - p.z())));
}


void Point3D::rotate_Z(const double angle)
{
    const double sinAngle = std::sin(angle);
    const double cosAngle = std::cos(angle);
    //add temp var
    double temp_x = m_x;
    
    m_x = temp_x * cosAngle + m_y * (-sinAngle);
    m_y = temp_x * sinAngle + m_y * cosAngle;
    
}

void Point3D::rotate_X(const double angle)
{
    const double sinAngle = std::sin(angle);
    const double cosAngle = std::cos(angle);
    //add temp var
    double temp_y = m_y;
    
    m_y = temp_y * cosAngle  + m_z * (-sinAngle);
    m_z = temp_y * sinAngle  + m_z * cosAngle;
}

void Point3D::translate_Z(const double height)
{
    m_z = m_z + height;
}
