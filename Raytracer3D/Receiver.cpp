//
//  Receiver.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Creates a Receiver and its position in 3d space.

#include "Receiver.hpp"

Receiver::Receiver() :
    Receiver(-1,0,0, Point3D(0,0,0), 0)
{
    
}

Receiver::Receiver(const int id, const double Bandwidth, const double center_freq,
                   const Point3D& center, const double boundary_radius) :
    id(id), Bandwidth(Bandwidth), center_freq(center_freq), center(center), boundary_radius(boundary_radius)
{
    boundary = Sphere(boundary_radius, center);
}

Sphere Receiver::get_Boundary()
{
    return boundary;
}

std::vector<Ray3D> Receiver::get_frame_data()
{
    return frame_data;
}
