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

Bounding_box::Bounding_box(Blade_surface& Bsurface){
    double max_Distace = 0; // greatest distance
    double point_Distance = 0; //distance between instance points
    
    for (int i = 0; i < Bsurface.getRibs()[0].getRibPoints().size(); i++) {
        //fist rib
        for (int j = 0; j < Bsurface.getRibs()[Bsurface.Rib_count].getRibPoints().size(); j++) {
            //last rib
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

Bounding_box::Bounding_box(Point3D& p1, Point3D& p2){
    
}