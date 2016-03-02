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

class Scene
{
public:
    Scene();
    
    Rotor get_rotor();
    Transmitter get_transmitter();
    Receiver get_receiver();
    
    void trace_scene(int num_rays);
    void trace_vect(Ray3D &test_ray, double &hitDistance, Vector3D &hitNormal, Point3D &hitPoint);
    void update();
    
    double getDistancePower(const double frequency, const double power, const double distance) const;
    
private:
    Rotor rotor;
    Transmitter transmitter;
    Receiver receiver;
    
};
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