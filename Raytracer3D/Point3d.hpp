//
//  Point3d.hpp
//  TestBlade
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//  Eric

//Creates 3D point in space.

#ifndef Point3d_hpp
#define Point3d_hpp

#include <stdio.h>
#include "Vector3d.hpp"

class Point3D
{
public:
    Point3D();
    explicit Point3D(const double x, const double y, const double z);
    explicit Point3D(const double y, const double z);
    
    Point3D operator-() const;
    Vector3D operator-(const Point3D& p) const;
    Point3D operator+(const Vector3D& v) const;
    Point3D operator-(const Vector3D& v) const;
    Point3D operator*(const double a) const;
    bool operator==(const Point3D& p) const;
    double distance(const Point3D& p) const;
    
    friend void swap(Point3D & a, Point3D & b);
    
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
    
    void rotate_Z(const double angle);
    void rotate_X(const double angle);
    
private:
    double m_x;
    double m_y;
    double m_z;
};

inline Point3D Point3D::operator-() const
{
    return Point3D(-m_x, -m_y, -m_z);
}

inline Vector3D Point3D::operator-(const Point3D& p) const
{
    return (Vector3D(m_x - p.x(), m_y - p.y(), m_z - p.z()));
}

inline Point3D Point3D::operator+(const Vector3D& v) const
{
    return (Point3D(m_x + v.x(), m_y + v.y(), m_z + v.z()));
}

inline Point3D Point3D::operator-(const Vector3D& v) const
{
    return (Point3D(m_x - v.x(), m_y - v.y(), m_z - v.z()));
}

inline Point3D Point3D::operator*(const double a) const
{
    return (Point3D(m_x * a, m_y * a, m_z * a));
}

Point3D operator*(double a, const Point3D& p);

inline Point3D operator*(double a, const Point3D& p)
{
    return (Point3D(a * p.x(), a * p.y(), a * p.z()));
}

inline bool Point3D::operator==(const Point3D& p) const
{
    if ((this->x()==p.x())&&(this->y()==p.y())&&(this->z()==p.z())) {
        return true;
    }
    else{
        return false;
    }
    
}


#endif /* Point3d_hpp */
