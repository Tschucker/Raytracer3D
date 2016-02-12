//
//  Rib.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Creates a Rib of the Blade airfoil shape from a data file containing 2D points

#include "Rib.hpp"

Rib::Rib()
{
}

Rib::Rib(int id, const Rib& x, const double delta_l)
{
    //shift all ponts in x axis by some ammount and generate new Rib
    this->id = id;
    for (int i = 0; i <x.RibPoints.size(); i++) {
        RibPoints.push_back(Point3D(x.RibPoints[i].x() + delta_l, x.RibPoints[i].y(), x.RibPoints[i].z()));
    }
    
    /*
    for (int i = 0; i<RibPoints.size(); i++) {
        std::cout <<"X: "<< RibPoints[i].x()<<" Y: "<< RibPoints[i].y() << " Z: " << RibPoints[i].z() << '\n';
    }
    */
}

Rib::Rib(int id ,const std::string& filename)
{
    //create points from file
    this->id = id;
    std::string line;
    std::ifstream myfile;
    myfile.open (filename);
    
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            std::string::size_type sz;
            double Y = std::stod (line,&sz);
            double Z = std::stod (line.substr(sz));
            RibPoints.push_back(Point3D(.001*Y, .001*Z));
            
            //std::cout << "Y: "<< Y << " Z: " << Z << '\n';
            
        }
        myfile.close();
        //std::cout << RibPoints.size() << '\n';
    }
    
    else std::cout << "Unable to open file \n";
    
    /*
    std::cout << "Test \n";
    for (int i = 0; i<RibPoints.size(); i++) {
        std::cout <<"X: "<< RibPoints[i].x()<<" Y: "<< RibPoints[i].y() << " Z: " << RibPoints[i].z() << '\n';
    }
    */
    
}

// needs to be done before blade rotates!!!
void Rib::pitch(const double angle)
{
    for (int i = 0; i<RibPoints.size(); i++) {
        RibPoints[i].rotate_X(angle);
    }
}

void Rib::rotate(const double angle)
{
    for (int i = 0; i<RibPoints.size(); i++) {
        RibPoints[i].rotate_Z(angle);
    }
}

std::vector<Point3D> Rib::getRibPoints()
{
    return RibPoints;
}

