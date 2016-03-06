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

Blade_surface::Blade_surface(const int id, const double length, const int Rib_count, Rib& origin_Rib):
    id(id), length(length), Rib_count(Rib_count)
{
    Ribs.push_back(origin_Rib);
    
    delta_l = length/Rib_count;
    
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
    box = Bounding_box(points);
}

void Blade_surface::create_surface()
{
    int nextPoint = 0;
    
    surface.clear();
    for (int i = 0; i < Ribs.size() - 1; i++) {
        for( int j = 0; j < Ribs[i].getRibPoints().size(); j++){
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
    points.clear();
    for (int i = 0; i < Ribs.size(); i++) {
        for (int j = 0; j < Ribs[i].getRibPoints().size(); j++) {
            points.push_back(Ribs[i].getRibPoints()[j]);
        }
    }
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
                    //need to use no cull otherwise wont fix all normals.
                    if (flipped==false && surface[j+s*triangles_per_strip].hitNoCull(testRay, h, v, p)) {
                        surface[i+s*triangles_per_strip].flipNormal();
                        flipped = true;
                        //TEST//std::cout << "flipped " << i + s*triangles_per_strip<< " hit  " << j+ s*triangles_per_strip << '\n';
                    }
                }
            }
        }
    }
}

bool Blade_surface::hit(const Ray3D &ray, double &hitDistance, Vector3D &hitNormal, Point3D &hitPoint)
{
    //need to make sure hits on triangles facing the opposite direction dont get hit!!
    for (int i = 0; i < surface.size(); i++) {
        if (surface[i].hit(ray, hitDistance, hitNormal, hitPoint)) {
            return true;
        }
    }
    return false;
}

void Blade_surface::update_surface()
{
    create_surface();
    for ( int i = 0; i < surface.size(); i++) {
        surface[i].updateNormal();
    }
    fix_surface_normals();
    update_bounding_box();
}

//in rad not sure which way yet
void Blade_surface::rotate_surface_Z(const double angle)
{
    for (int i = 0; i<Ribs.size(); i++) {
        Ribs[i].rotate(angle);
    }
    update_surface();
}

//only pitch before blade rotates !!! in rad
void Blade_surface::pitch_surface_X(const double angle)
{
    for (int i = 0; i<Ribs.size(); i++) {
        Ribs[i].pitch(angle);
    }
    update_surface();
}

//translate after pitch.
void Blade_surface::height_surface_Z(const double height)
{
    for (int i = 0; i<Ribs.size(); i++) {
        Ribs[i].height(height);
    }
    
    update_surface();
}

void Blade_surface::update_bounding_box()
{
    box = Bounding_box(points);
}

std::vector<Rib> Blade_surface::getRibs()
{
    return Ribs;
}
std::vector<Triangle> Blade_surface::getSurface()
{
    return surface;
}
std::vector<Point3D> Blade_surface::getPoints()
{
    return points;
}

Bounding_box Blade_surface::getBox()
{
    update_bounding_box();
    return box;
}