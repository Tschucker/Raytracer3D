//
//  Transmitter.hpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Creates Transmitter and its location in 3d space.

#ifndef Transmitter_hpp
#define Transmitter_hpp

#include <stdio.h>
#include <vector>
#include <random>
#include "Point3d.hpp"
#include "Sphere.hpp"
#include "Ray3d.hpp"

class Transmitter
{
public:
    int id;
    double frequency;
    Point3D center;
    double power;
    
    Transmitter();
    explicit Transmitter(const int id, const double frequency, const double power, const Point3D& center, const double r);
    
    void setPower(const double power);
    double getPower() const;
    
    Ray3D makeRay();
    Ray3D makeRay_disk(const double height);
    Ray3D makeRay(const Vector3D &rayDirection);
    
private:
    //std::vector<Ray3D> Rays; //not sure if i need this still
    std::uniform_real_distribution<double> rayDirectionDistribution;
    
    std::uniform_real_distribution<double> rayDirectionDistribution_r;
    std::uniform_real_distribution<double> rayDirectionDistribution_theta;
    
};




#endif /* Transmitter_hpp */
