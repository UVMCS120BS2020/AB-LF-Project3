//
// Created by Luke on 1/20/2020.
//

#include <cmath>
#include <experimental/optional>
#include "Rectilinear_Lens.h"
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

typedef optional<string> opt_string;

/********************** Rectilinear_Lens class **********************/

Rectilinear_Lens::Rectilinear_Lens() : Lens() {
    type = rectilinear;
}

Rectilinear_Lens::Rectilinear_Lens(double focal_length_, double f_stop_, opt_string &name_) : Lens(focal_length_, f_stop_, name_) {
    type = rectilinear;
}

double Rectilinear_Lens::field_of_view_horizontal(double magnification, double frame_width) const {
    // Horizontal FOV = 2 * ARCTAN( w / (2*f*(m+1)) ) -> convert to degrees
    // w = frame width, f = focal length, m = magnification
    double m = magnification;
    double w = frame_width;
    double f = focal_length;
    double h_fov = 2 * atan(w / (2*f*(m+1))) * (180.0 / M_PI);
    return h_fov;
}