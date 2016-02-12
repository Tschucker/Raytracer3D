//
//  Blade_surface.hpp
//  TestBlade
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Blade_surface creates a surface of triangles between each of the Ribs which
//forms a 3d rotor blade.

#ifndef Blade_surface_hpp
#define Blade_surface_hpp

#include <stdio.h>
#include "Triangle.hpp"
#include "Rib.hpp"

class Blade_surface
{
public:
    int id;
    double length;
    double delta_l;
    int Rib_count;
    Rib origin_Rib;
    
    Blade_surface();
    explicit Blade_surface(const int id, const double length, const int Rib_count, const Rib& origin_Rib);
    
    void create_surface();
    void update_surface();
    
    void rotate_surface_Z(const double angle);
    void pitch_surface_X(const double angle);
    
    std::vector<Rib> getRibs();
    std::vector<Triangle> getSurface();
    
    
private:
    std::vector<Rib> Ribs;
    std::vector<Triangle> surface;
    
    void fix_surface_normals();
    
};


#endif /* Blade_surface_hpp */
