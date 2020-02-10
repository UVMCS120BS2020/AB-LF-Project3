//
// Created by Luke on 2/4/2020.
//

#include "globals.h"
#include "Lens.h"
#include <cmath>

// the conversion factor between mm and meters
double const MM_PER_METER = 1000;

double calculate_magnification(Lens const &lens, double subject_distance) {
    // magnification = f / (s-f)
    // f = focal length, s = subject distance
    double s = subject_distance*MM_PER_METER; // convert to mm, simplify var name for clarity
    double f = lens.get_focal_length();
    double magnification = f / (s - f);
    return magnification;
}

double field_of_view_horizontal(Lens const &lens, double magnification) {
    // Horizontal FOV = 2 * ARCTAN( w / (2*f*(m+1)) ) -> convert to degrees
    // w = frame width, f = focal length, m = magnification
    double m = magnification;
    double w = lens.get_frame_width();
    double f = lens.get_focal_length();
    double h_fov = 2 * atan(w / (2*f*(m+1))) * (180.0 / M_PI);
    return h_fov;
}