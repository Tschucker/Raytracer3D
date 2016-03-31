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
                   const Point3D& center, const double boundary_radius, const std::string& samplefile_name, const std::string& dopplerfile_name) :
    id(id), Bandwidth(Bandwidth), center_freq(center_freq), center(center), boundary_radius(boundary_radius)
{
    boundary = Sphere(boundary_radius, center);
    sample_file = samplefile_name;
    doppler_file = dopplerfile_name;
    
    //clear data
    std::ofstream myfile;
    myfile.open (sample_file);
    myfile.close();
    
    myfile.open (doppler_file);
    myfile.close();}

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
    double cos_d;
    double sin_d;
    const double t_s = 1 / get_sampling_rate();
    std::complex<double> sample;
    
    std::vector<std::complex<double>> resolution_samples;
    
    std::ofstream myfile;
    std::ofstream dopfile;
    myfile.open (sample_file, std::ios_base::app);
    dopfile.open (doppler_file, std::ios_base::app);
    
    for (int i = 0; i < frame_data.size(); i++) {
        
        amplitude = std::sqrt(frame_data[i].power);
        omega = 2.0 * M_PI * (frame_data[i].frequency - center_freq);
        dopfile << omega << "," << amplitude << '\n';
        t = frame_data[i].distance / SPEED_OF_LIGHT;
        
        cos_d = std::cos(omega * t_s);
        sin_d = std::sin(omega * t_s);
        if(resolution_samples.size() > 1){
            resolution_samples[0] += (amplitude * std::complex<double>(std::cos(omega * t), std::sin(omega * t)));
            for (int j = 1; j < 1000; ++j)
            {
                resolution_samples[j] += amplitude * std::complex<double>(std::cos(omega * (t + (t_s * j))), std::sin(omega * (t + (t_s * j))));
            }
        }
        else{
            resolution_samples.push_back(amplitude * std::complex<double>(std::cos(omega * t), std::sin(omega * t)));
            for (int j = 1; j < 1000; ++j)
            {
                resolution_samples.push_back(amplitude * std::complex<double>(std::cos(omega * (t + (t_s * j))), std::sin(omega * (t + (t_s * j)))));
            }
        }
        
    }
    
    for(int j = 0; j < resolution_samples.size(); j++){
        if (resolution_samples[j].imag() < 0) {
            myfile << resolution_samples[j].real() << resolution_samples[j].imag() << "i" << ",";
        }
        else
            myfile << resolution_samples[j].real() << "+" << resolution_samples[j].imag() << "i" << "," ;
    }
    resolution_samples.clear();
    
    myfile.close();
    dopfile.close();
    frame_data.clear();
}