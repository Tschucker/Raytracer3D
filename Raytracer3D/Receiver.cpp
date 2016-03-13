//
//  Receiver.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

//Creates a Receiver and its position in 3d space.

#include "Receiver.hpp"

Receiver::Receiver()
{

}

Receiver::Receiver(const int id, const double Bandwidth, const double center_freq,
                   const Point3D& center, const double boundary_radius, const std::string& savefile_name) :
    id(id), Bandwidth(Bandwidth), center_freq(center_freq), center(center), boundary_radius(boundary_radius)
{
    boundary = Sphere(boundary_radius, center);
    file = savefile_name;
    std::ofstream myfile;
    myfile.open (file);
    myfile << "%RX data " << '\n';
    myfile << "samples = [";
    myfile.close();
}

Sphere Receiver::get_Boundary()
{
    return boundary;
}

double Receiver::get_sampling_rate()
{
    sampling_rate = Bandwidth*2;
    return sampling_rate;
}

std::vector<Ray3D> Receiver::get_frame_data()
{
    return frame_data;
}

void Receiver::save_ray_toFrame(Ray3D &ray){
    frame_data.push_back(ray);
}

void Receiver::save_to_file(){
    double amplitude;
    double omega;
    double t;
    std::complex<double> sample;
    
    std::sort(frame_data.begin(), frame_data.end(),
              [] (Ray3D const& a, Ray3D const& b) { return a.distance < b.distance; });
    
    std::ofstream myfile;
    myfile.open (file, std::ios_base::app);
    for (int i = 0; i < frame_data.size(); i++) {
        amplitude = std::sqrt(frame_data[i].power);
        omega = 2.0 * M_PI * (frame_data[i].frequency - center_freq);
        //std::cout << omega << " " << amplitude << " " << frame_data[i].frequency - center_freq << '\n';
        t = frame_data[i].distance / SPEED_OF_LIGHT;
        sample = amplitude * std::complex<double>(std::cos(omega * t), std::sin(omega * t));
        myfile << "complex" << sample << ";" << '\n';
    }
    
    myfile.close();
    frame_data.clear();
}