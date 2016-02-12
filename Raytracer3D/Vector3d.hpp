//
//  Vector3d.hpp
//  TestBlade
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//  Eric

//Creates vector.

#ifndef Vector3d_hpp
#define Vector3d_hpp

#include <stdio.h>
#include <algorithm>

class Vector3D
{
public:
    Vector3D();
    explicit Vector3D(const double x, const double y, const double z);
    
    Vector3D operator-(void) const;
    Vector3D operator*(const double a) const;
    Vector3D operator/(const double a) const;
    Vector3D operator+(const Vector3D& v) const;
    Vector3D operator-(const Vector3D& v) const;
    double operator*(const Vector3D& b) const;
    Vector3D operator^(const Vector3D& v) const;
    
    inline double x() const
    {
        return m_x;
    }
    
    inline double y() const
    {
        return m_y;
    }
    
    inline double z() const
    {
        return m_z;
    }
    
    double dotProduct(const Vector3D& v) const;
    Vector3D crossProduct(const Vector3D& v) const;
    
    double length() const;
    Vector3D normalized() const;
    Vector3D rotatedAboutZ(const double angle) const;
    bool isNormal() const;
    
private:
    double m_x;
    double m_y;
    double m_z;
};

inline Vector3D Vector3D::operator-(void) const
{
    return Vector3D(-m_x, -m_y, -m_z);
}

inline Vector3D Vector3D::operator*(const double a) const
{
    return Vector3D(m_x * a, m_y * a, m_z * a);
}

inline Vector3D Vector3D::operator/(const double a) const
{
    return Vector3D(m_x / a, m_y / a, m_z / a);
}

inline Vector3D Vector3D::operator+(const Vector3D &v) const
{
    return Vector3D(m_x + v.x(), m_y + v.y(), m_z + v.z());
}

inline Vector3D Vector3D::operator-(const Vector3D &v) const
{
    return Vector3D(m_x - v.x(), m_y - v.y(), m_z - v.z());
}

inline double Vector3D::operator*(const Vector3D &v) const
{
    return dotProduct(v);
}

inline Vector3D Vector3D::operator^(const Vector3D &v) const
{
    return crossProduct(v);
}

Vector3D operator*(const double a, const Vector3D &v);

inline Vector3D operator*(const double a, const Vector3D &v)
{
    return Vector3D(a * v.x(), a * v.y(), a * v.z());
}

inline double Vector3D::dotProduct(const Vector3D &v) const
{
    return m_x * v.x() + m_y * v.y() + m_z * v.z();
}

inline Vector3D Vector3D::crossProduct(const Vector3D &v) const
{
    return Vector3D(m_y * v.z() - m_z * v.y(), m_z * v.x() - m_x * v.z(), m_x * v.y() - m_y * v.x());
}


#endif /* Vector3d_hpp */
