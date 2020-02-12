//
// Created by Luke on 1/20/2020.
//

#include "Lens.h"
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

typedef optional<string> opt_string;

/********************** Lens class **********************/

Lens::Lens() {

    // the distance between the center of a lens and its focal plane
    focal_length = 50.0;
    // f/stop = focal length (mm) / aperture diameter (mm)
    f_stop = 4.0;
    // Name of the lens, by default nothing.
    name = nullopt;

}

Lens::Lens(double focal_length_, double f_stop_, opt_string &name_) {

    this -> focal_length = focal_length_;
    this -> f_stop = f_stop_;
    this -> name = name_;

}

double Lens::get_f_stop() const {
    return f_stop;
}

void Lens::set_f_stop(double f_stop_) {
    this -> f_stop = f_stop_;
}

double Lens::get_focal_length() const {
    return focal_length;
}

void Lens::set_focal_length(double focal_length_) {
    this -> focal_length = focal_length_;
}

opt_string Lens::get_name() const {
    return name;
}

void Lens::set_name(opt_string &name_) {
    this -> name = name_;
}

void Lens::clear_name() {
    name = nullopt;
}

// the conversion factor between mm and meters
double const MM_PER_METER = 1000;

// TODO: MOVE DOF FUNCTION TO PHOTOGRAPH CLASS
//double Lens::depth_of_field(double subject_distance) {
//    // EQ from: https://damienfournier.co/dof-the-simplified-formula-to-understand-dof/
//    // DOF = ((s*(f*f)) / ((f*f) - A*c*(s-f))) - ((s*(f*f)) / ((f*f) + A*c*(s-f)))
//    // s = subject distance, A = f/stop, c = circle of confusion, f = focal length
//    double s = subject_distance*MM_PER_METER; // put subject distance in mm, simplify var name for clarity
//    double A = f_stop; // simplify var names
//    double c = circle_of_confusion;
//    double f = focal_length;
//
//    double dof = ((s*(f*f)) / ((f*f) - A*c*(s-f))) - ((s*(f*f)) / ((f*f) + A*c*(s-f)));
//    dof /= MM_PER_METER; // put final answer in meters
//    // DOF will calculate negative if subject distance is beyond the hyper-focal distance of the lens.
//    if (dof > 0) {
//        return dof;
//    }
//    return -1.0;
//}