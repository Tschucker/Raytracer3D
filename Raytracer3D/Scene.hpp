//
//  Scene.hpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 2/25/16.
//  Copyright © 2016 BWAC. All rights reserved.
//
// Describes the scene of objects.

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include "Rotor.hpp"
#include "Transmitter.hpp"
#include "Receiver.hpp"

#endif /* Scene_hpp */

#define SPEED_OF_LIGHT 299792458
#define EPSILON 0.0000001

class Scene
{
public:
    Scene();
    
    Rotor get_rotor();
    Transmitter get_transmitter();
    Receiver get_receiver();
    
    void trace_scene(int num_rays);
    void trace_vect(Ray3D &test_ray, double &hitDistance, Vector3D &hitNormal, Point3D &hitPoint);
    void update(double angle);
    
    double getDistancePower(const double frequency, const double power, const double distance) const;
    double getDoppler(Ray3D &test_ray, Vector3D &hitNormal, Point3D &hitPoint, double RPM) const;
    
private:
    Rotor rotor;
    Transmitter transmitter;
    Receiver receiver;
    
};

inline double Scene::getDoppler(Ray3D &test_ray, Vector3D &hitNormal, Point3D &hitPoint, double RPM) const
{
    //!!!!! doppler does not get affected by the normal, need to check this. not sure if this is correct.
    double frequency = test_ray.frequency;
    
    //form vect in direction of rotation...?
    Vector3D hit_point_radius_perp(-hitPoint.y(), hitPoint.x(), 0);
    
    //find radial distance
    double hit_point_radius_dist = std::sqrt((hitPoint.x()*hitPoint.x()) + (hitPoint.y()*hitPoint.y()));
    
    //determine reflection make sure is a vector
    Vector3D reflection = -test_ray.direction + (2 * hitNormal) * (test_ray.direction * hitNormal);
    
    double omega_r = (2*M_PI/60)*RPM;
    double wave_length = SPEED_OF_LIGHT/frequency;
    
    frequency = frequency + (((hit_point_radius_dist*omega_r)/wave_length)
        *(hit_point_radius_perp.normalized()*reflection.normalized()));
    
    return frequency;
}

//Eric
inline double Scene::getDistancePower(const double frequency, const double power, const double distance) const
{
    const double waveLength = SPEED_OF_LIGHT / frequency;
    const double pathLossFactor = std::pow(waveLength / distance, 2);
    if (pathLossFactor < 1.0)
    {
        return power * pathLossFactor;
    }
    
    return power;
}