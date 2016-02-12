//
//  Transmitter.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Creates Transmitter and its location in 3d space.

#include "Transmitter.hpp"
#include <iostream>

#define SPEED_OF_LIGHT 299792458

std::mt19937 generator;

Transmitter::Transmitter() :
    Transmitter(-1, 0, 0, Point3D(0,0,0))
{
    rayDirectionDistribution = std::uniform_real_distribution<double>(-1, 1);
}

Transmitter::Transmitter(const int id, const double frequency, const double power, const Point3D& center) :
    id(id),frequency(frequency),power(power),center(center),rayDirectionDistribution(-1,1)
{
    
}

double Transmitter::getPower() const
{
    return power;
}

void Transmitter::setPower(const double power)
{
    this->power = power;
}

//Marsaglia (1972) http://mathworld.wolfram.com/SpherePointPicking.html verified in matlab using scatter3(x,y,z).
Ray3D Transmitter::makeRay()
{
    double x1 = rayDirectionDistribution(generator);
    double x2 = rayDirectionDistribution(generator);
    double pointReject = std::pow(x1, 2) + std::pow(x2, 2);
    //reject and regenerate any 2 points that follow the condition x1^2 + x2^2 >= 1;
    while (pointReject >= 1) {
        x1 = rayDirectionDistribution(generator);
        x2 = rayDirectionDistribution(generator);
        pointReject = std::pow(x1, 2) + std::pow(x2, 2);
    }
    
    //std::cout << x1 << " " << x2 <<'\n';
    
    //place point on x,y,z coordinates of the sphere
    const double x = 2*x1*std::sqrt(1 - std::pow(x1, 2) - std::pow(x2, 2)) + this->center.x();
    const double y = 2*x2*std::sqrt(1 - std::pow(x1, 2) - std::pow(x2, 2)) + this->center.y();
    const double z = 1 - (2*(std::pow(x1, 2) + std::pow(x2, 2))) + this->center.z();
    
    //std::cout << (std::pow(x - this->center.x(), 2) + std::pow(y - this->center.y(), 2) + std::pow(z - this->center.z(), 2))<<'\n';
    std::cout << x << " " << y << " " << z << ";" << '\n';
    return makeRay(Vector3D(x, y, z));
    
}


//need to fix this
Ray3D Transmitter::makeRay(const Vector3D &rayDirection)
{
    //const double dopplerCoefficient = getDopplerCoefficient(rayDirection, velocity);
    const double radiantIntensity = getPower() / (4.0 * M_PI); // power per unit solid angle
    
    //  + frequencyDistribution(generator)
    return Ray3D(center, rayDirection, radiantIntensity, frequency);
    
}
