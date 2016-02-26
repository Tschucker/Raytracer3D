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

class Scene
{
public:
    Scene();
    //explicit Scene();
    
    Rotor get_rotor();
    Transmitter get_transmitter();
    Receiver get_receiver();
    
    void trace(int num_rays);
    void update();
    
private:
    Rotor rotor;
    Transmitter transmitter;
    Receiver receiver;
    
};