//
//  Bounding_box.cpp
//  TestBlade
//
//  Created by Thomas Schucker on 11/23/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

#include "Bounding_box.hpp"

Bounding_box::Bounding_box(){
    
}

Bounding_box::Bounding_box(Blade_surface& Bsurface){
    //find p1 on the origional rib
    
    //find p2 on the last rib

    //iterate over the points on ribs 0 and last for longest distance.
    double max_Distace = 0; // greatest distance
    double point_Distance = 0; //distance between instance points
    
    for (int i = 0; i < Bsurface.getRibs()[0].getRibPoints().size(); i++) {
        //fist rib
        for (int j = 0; j < Bsurface.getRibs()[Bsurface.Rib_count].getRibPoints().size(); j++) {
            //last rib
            //TODO calc distace find max.
        }
    }
}