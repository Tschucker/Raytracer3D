//
//  Receiver.hpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Creates a Receiver and its position in 3d space.

#ifndef Receiver_hpp
#define Receiver_hpp

#include <stdio.h>
#include "Point3d.hpp"
#include "Sphere.hpp"

class Receiver
{
public:
    int id;
    double Bandwidth;
    double center_freq;
    double Resolution;
    double boundary_radius;
    Point3D center;
    
    
    Receiver();
    explicit Receiver(const int id, const double Bandwidth, const double center_freq,
                      const Point3D& center, const double boundary_radius);
    
    Sphere get_Boundary();
    double get_sampling_rate();
    std::vector<Ray3D> get_frame_data();
    
private:
    Sphere boundary;
    std::vector<Ray3D> frame_data;
    double sampling_rate;
};


#endif /* Receiver_hpp */
