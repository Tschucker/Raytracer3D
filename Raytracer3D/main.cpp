//
//  main.cpp
//  Raytracer3D
//
//  Created by Thomas Schucker on 11/19/15.
//  Copyright © 2015 BWAC. All rights reserved.
//

#include <iostream>
#include "Rib.hpp"
#include "Blade_surface.hpp"
#include "Transmitter.hpp"
#include "Sphere.hpp"
#include "Bounding_box.hpp"
#include "Scene.hpp"
#include "Triangle.hpp"

#include <sstream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(int argc, char **argv) {
    // insert code here... for testing
    std::cout << "Raytracer3D main test!\n";
    
    Scene s;
    s.trace_scene(1000);
    
    /*
    //test sphere hit
    Point3D pt(0, 0, 10);
    Sphere sp(1, pt);
    
    Ray3D testRay(Point3D(0, 10, 0), Vector3D(0, -5, 5));
    double hitDistance;
    Vector3D hitNormal;
    Point3D hitPoint;
    
    if (sp.hit(testRay, hitDistance, hitNormal, hitPoint)) {
        std::cout << "ray hit test succeed" << '\n';
    }
    */
    /*
    //output blade points for matlab
    std::ofstream blade_vertex_file;
    std::ofstream blade_face_file;
    std::ofstream sample_points_file;
    blade_vertex_file.open("/Users/tschucker/xcode projects/Raytracer3D/blade_verts.csv");
    blade_face_file.open("/Users/tschucker/xcode projects/Raytracer3D/blade_faces.csv");
    sample_points_file.open("/Users/tschucker/xcode projects/Raytracer3D/sample_points.csv");
    
    int j = 1;
    std::vector<Point3D> test;
    for (int b = 0; b<s.get_rotor().get_Blades().size(); b++) {
        for (int i = 0 ; i < s.get_rotor().get_Blades()[b].getSurface().size(); i++) {
            Triangle temp = s.get_rotor().get_Blades()[b].getSurface()[i];
            
            blade_vertex_file << temp.getVertex0().x() << "," << temp.getVertex0().y() << "," << temp.getVertex0().z() << '\n';
            blade_vertex_file << temp.getVertex1().x() << "," << temp.getVertex1().y() << "," << temp.getVertex1().z() << '\n';
            blade_vertex_file << temp.getVertex2().x() << "," << temp.getVertex2().y() << "," << temp.getVertex2().z() << '\n';
            
            blade_face_file << j << "," << j+1 << "," << j+2 << '\n';
            j = j + 3;
        }
    }
    
    for (int i = 0; i < 1000; i++) {
        Ray3D test_ray = s.get_transmitter().makeRay_disk(s.get_rotor().get_height()-.01);
        sample_points_file << test_ray.direction.x() << "," << test_ray.direction.y() << "," << test_ray.direction.z() << '\n';
    }
    sample_points_file.close();
    blade_face_file.close();
    blade_vertex_file.close();
    */
    /* //test works
    Point3D pt1(1,0,10);
    std::cout << "test_point: " << pt1.x() << " " << pt1.y() << " " << pt1.z() << '\n';
    pt1.rotate_Z(M_PI/2);
    std::cout << "test_point_after: " << pt1.x() << " " << pt1.y() << " " << pt1.z() << '\n';
    */
    
    /*
    double test_cos = std::cos(M_PI/2);
    std::cout << "cos of pi/2: " << test_cos << '\n';
    double test_sin = std::sin(M_PI/2);
    std::cout << "sin of pi/2: " << test_sin << '\n';
    */
    
    /*
    const std::string test = "/Users/tschucker/xcode projects/TestBlade/TestBlade/rib.txt";
    const Rib rib_one(0,test);
    
    Blade_surface Bsurface(1,5,10,rib_one);
    std::cout << "delta_l: " << Bsurface.delta_l << '\n';
    */
    
    //TEST//
    /*
    Blade_surface Bsurface = s.get_rotor().get_Blades()[0];
    
    for (int i = 0; i < Bsurface.getRibs().size(); i++) {
        std::cout << Bsurface.getRibs()[i].getRibPoints()[0].x() << '\n';
        std::cout << Bsurface.getRibs()[i].getRibPoints()[0].y() << '\n';
        std::cout << Bsurface.getRibs()[i].getRibPoints()[0].z() << '\n';
        std::cout << '\n';
    }
    
    std::cout << "after Rotation " << '\n';
    s.update(M_PI/2);
    
    
    for (int i = 0; i < s.get_rotor().get_Blades()[0].getPoints().size(); i++) {
        Point3D test_pt = s.get_rotor().get_Blades()[0].getPoints()[i];
        std::cout << "before: " << test_pt.x() << " " << test_pt.y() << " " << test_pt.z() << '\n';
        test_pt.rotate_Z(M_PI/2);
        std::cout << "after: " << test_pt.x() << " " << test_pt.y() << " " << test_pt.z() << '\n';
        s.get_rotor().get_Blades()[0].getPoints()[i] = test_pt;
    }
    
    for (int i = 0; i < Bsurface.getPoints().size(); i++) {
        std::cout << Bsurface.getPoints()[i].x() << '\n';
        std::cout << Bsurface.getPoints()[i].y() << '\n';
        std::cout << Bsurface.getPoints()[i].z() << '\n';
        std::cout << '\n';
    }
    */
    
    //std::cout << "surface triangles: "<< Bsurface.getSurface().size()<< '\n';
    
    /*
    Transmitter tr(0, 10, 10, Point3D(5, 5, 0), 5);
    for (int i = 0; i <2000; i++) {
        tr.makeRay_disk(12);
    }
    */
    
    //Bounding_box bbox(Bsurface);
    
    
    /*//TEST//
    Point3D pt(0, .9, 10);
    Sphere s(1,pt);
    
    Ray3D testRay;
    double hitDistance;
    Vector3D hitNormal;
    Point3D hitPoint;
    
    if (s.hit(testRay, hitDistance, hitNormal, hitPoint)) {
        std::cout << "ray hit" << '\n';
    }
    */
    
    //TEST axis aligned bounding box max and min
    /*
    Bounding_box box(Bsurface.getPoints());
    
    std::cout << Bsurface.getBox().min_point.x() << '\n';
    std::cout << Bsurface.getBox().max_point.x() << '\n';
    */
    
    //minimum double value
    //std::cout << std::defaultfloat << std::numeric_limits<double>::min() << '\n';
    
    //test scene generation.
    
    return 0;
}
