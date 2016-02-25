//
//  Blade_surface.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Blade_surface creates a surface of triangles between each of the Ribs which
//forms a 3d rotor blade.

#include "Blade_surface.hpp"

Blade_surface::Blade_surface()
{
    
}

Blade_surface::Blade_surface(const int id, const double length, const int Rib_count, const Rib& origin_Rib)
{
    this->id = id;
    this->length = length;
    this->Rib_count = Rib_count;
    
    Ribs.push_back(origin_Rib);
    
    this->delta_l = length/Rib_count;
    
    for (int i = 1; i < Rib_count + 1; i++) //add 1 to get correct blade length in m
    {
        Ribs.push_back( Rib(i, Ribs[i -1], delta_l));
    }
    
    for (int i = 0; i < Ribs.size(); i++) {
        for (int j = 0; j < Ribs[i].getRibPoints().size(); j++) {
            points.push_back(Ribs[i].getRibPoints()[j]);
        }
    }
    
    create_surface();
    Bounding_box bbox(this->points);
    box = bbox;
    
    
}

void Blade_surface::create_surface()
{
    int nextPoint = 0;
    
    for (int i = 0; i < Ribs.size() - 1; i++) {
        for( int j = 0; j < Ribs[i].getRibPoints().size(); j++){
            //TEST//std::cout << &Ribs[i].getRibPoints()[j] << j << '\n';
            if (j + 1 == Ribs[i].getRibPoints().size()) {
                nextPoint = 0;
            }
            else{
                nextPoint = j+1;
            }
            
            surface.push_back(Triangle(Ribs[i].getRibPoints()[j], Ribs[i].getRibPoints()[nextPoint], Ribs[i+1].getRibPoints()[j]));
            surface.push_back(Triangle(Ribs[i+1].getRibPoints()[j], Ribs[i+1].getRibPoints()[nextPoint], Ribs[i].getRibPoints()[nextPoint]));
        }
    }
    //adjust normals so that they all point outwards. (only look at triangles within the strip that the triangel is in.)
    fix_surface_normals();
    
    /* ///TEST////
    for ( int i = 0; i < surface.size(); i++) {
        std::cout << surface[i].getVertex0().x() << ' ' << surface[i].getVertex0().y() << ' ' << surface[i].getVertex0().z() << '\n';
        std::cout << surface[i].getVertex1().x() << ' ' << surface[i].getVertex1().y() << ' ' << surface[i].getVertex1().z() << '\n';
        std::cout << surface[i].getVertex2().x() << ' ' << surface[i].getVertex2().y() << ' ' << surface[i].getVertex2().z() << '\n';
        std::cout << i << '\n'<< '\n';
        
    }
     */
}

void Blade_surface::fix_surface_normals(){
    
    int strips = this->Rib_count;
    unsigned long triangles_per_strip = surface.size()/strips;
    
    for (int s = 0; s < strips; s++) {
        for (int i = 0; i < triangles_per_strip; i++) {
            bool flipped = false;
            for (int j = 0; j < triangles_per_strip; j++) {
                if (surface[i+s*triangles_per_strip] == surface[j+s*triangles_per_strip]) {
                    //TEST//std::cout << "same " << i+ s*triangles_per_strip << '\n';
                }
                else{
                    double h;
                    Vector3D v;
                    Point3D p;
                    Ray3D testRay(surface[i+s*triangles_per_strip].centroid(), surface[i+s*triangles_per_strip].getNormal(),0,0);
                    if (flipped==false && surface[j+s*triangles_per_strip].hit(testRay, h, v, p)) {
                        surface[i+s*triangles_per_strip].flipNormal();
                        flipped = true;
                        //TEST//std::cout << "flipped " << i + s*triangles_per_strip<< " hit  " << j+ s*triangles_per_strip << '\n';
                    }
                }
            }
        }
    }
    
}

void Blade_surface::update_surface()
{
    for ( int i = 0; i < surface.size(); i++) {
        surface[i].updateNormal();
    }
}

//in rad not sure which way yet
void Blade_surface::rotate_surface_Z(const double angle)
{
    for (int i = 0; i<Ribs.size(); i++) {
        Ribs[i].rotate(angle);
    }
    update_surface();
    update_bounding_box();
}

//only pitch before blade rotates !!! in rad
void Blade_surface::pitch_surface_X(const double angle)
{
    for (int i = 0; i<Ribs.size(); i++) {
        Ribs[i].pitch(angle);
    }
    update_surface();
    update_bounding_box();
}

//translate after pitch.
void Blade_surface::height_surface_Z(const double height)
{
    for (int i = 0; i<Ribs.size(); i++) {
        Ribs[i].height(height);
    }
    update_surface();
    update_bounding_box();
}

void Blade_surface::update_bounding_box()
{
    Bounding_box bbox(this->points);
    box = bbox;
}


std::vector<Rib> Blade_surface::getRibs() const
{
    return Ribs;
}
std::vector<Triangle> Blade_surface::getSurface() const
{
    return surface;
}
std::vector<Point3D> Blade_surface::getPoints() const
{
    return points;
}
Bounding_box Blade_surface::getBox()
{
    update_bounding_box();
    return box;
}