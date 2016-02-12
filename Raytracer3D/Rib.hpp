//
//  Rib.hpp
//  TestBlade
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Creates a Rib of the Blade airfoil shape from a data file containing 2D points

#ifndef Rib_hpp
#define Rib_hpp

#include <stdio.h>
#include "Point3d.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

class Rib
{
public:
    
    Rib();
    explicit Rib(int id ,const Rib& x, const double delta_l);
    explicit Rib(int id ,const std::string &filename);
    
    int id;
    std::vector<Point3D> getRibPoints();
    
    void pitch(const double angle);
    void rotate(const double angle);
    
private:
    std::vector<Point3D> RibPoints;
    
};

#endif /* Rib_hpp */
