//
//  Bounding_box.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/23/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

#include "Bounding_box.hpp"

Bounding_box::Bounding_box(){
    
}

//not axis aligned
/*
Bounding_box::Bounding_box(Blade_surface& Bsurface){
    double max_Distace = 0; // greatest distance
    double point_Distance = 0; //distance between instance points
    
    for (int i = 0; i < Bsurface.getRibs()[0].getRibPoints().size(); i++) { //fist rib
        for (int j = 0; j < Bsurface.getRibs()[Bsurface.Rib_count].getRibPoints().size(); j++) { //last rib
            //calc distace find max.
            point_Distance = Bsurface.getRibs()[0].getRibPoints()[i].distance(Bsurface.getRibs()[Bsurface.Rib_count].getRibPoints()[j]);
            if (point_Distance > max_Distace) {
                max_Distace = point_Distance; //update max distance
                //update points
                p1 = Bsurface.getRibs()[0].getRibPoints()[i];
                p2 = Bsurface.getRibs()[Bsurface.Rib_count].getRibPoints()[j];
            }
        }
    }
}
 */

//for axis aligned
Bounding_box::Bounding_box(Blade_surface& Bsurface){
    double x_min = 100, y_min = 100, z_min = 100;
    double x_max = 0, y_max = 0, z_max = 0;
    
    for (int i = 0; i < Bsurface.getPoints().size(); i++) {
        x_min = std::min(x_min, Bsurface.getPoints()[i].x());
        y_min = std::min(y_min, Bsurface.getPoints()[i].y());
        z_min = std::min(z_min, Bsurface.getPoints()[i].z());
        
        x_max = std::max(x_max, Bsurface.getPoints()[i].x());
        y_max = std::max(y_max, Bsurface.getPoints()[i].y());
        z_max = std::max(z_max, Bsurface.getPoints()[i].z());
    }
    Point3D min(x_min, y_min, z_min);
    Point3D max(x_max, y_max, z_max);
    
    min_point = min;
    max_point = max;
    
}

bool Bounding_box::hit(){
    //TODO math for hit on 3d cube.
    return true;
}