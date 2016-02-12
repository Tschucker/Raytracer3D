//
//  Vector3d.cpp
//  TestBlade
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//  Eric

//Creates vector.

#include "Vector3d.hpp"
#include <cmath>

#define EPSILON 0.000001

Vector3D::Vector3D() :
m_x(0.0), m_y(0.0), m_z(0.0)
{
}

Vector3D::Vector3D(const double x, const double y, const double z) :
m_x(x), m_y(y), m_z(z)
{
}

double Vector3D::length() const
{
    return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

bool Vector3D::isNormal() const
{
    return std::abs(length() - 1.0) < EPSILON;
}

Vector3D Vector3D::normalized() const
{
    const double len = length();
    if (len == 0.0)
    {
        return Vector3D(0.0, 0.0, 0.0);
    }
    else
    {
        return Vector3D(m_x / len, m_y / len, m_z / len);
    }
}

Vector3D Vector3D::rotatedAboutZ(const double angle) const
{
    const double sinAngle = std::sin(angle);
    const double cosAngle = std::cos(angle);
    
    const double nx = m_x * cosAngle + m_y * (-sinAngle);
    const double ny = m_x * sinAngle + m_y * cosAngle;
    const double nz = m_z;
    
    return Vector3D(nx, ny, nz);
}

