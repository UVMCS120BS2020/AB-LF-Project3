//
// Created by Luke on 2/12/2020.
//

#include <cmath>
#include "Photograph.h"

Photograph::Photograph(Camera &camera_, double subject_distance_) {
    camera = camera_;
    subject_distance = subject_distance_;
}

Camera Photograph::get_camera() const {
    return camera;
}

void Photograph::set_camera(Camera &camera_) {
    camera = camera_;
}

double Photograph::get_subject_distance() const {
    return subject_distance;
}

void Photograph::set_subject_distance(double subject_distance_) {
    Photograph::subject_distance = subject_distance_;
}

double Photograph::depth_of_field() {
    // EQ from: https://damienfournier.co/dof-the-simplified-formula-to-understand-dof/
    // DOF = ((s*(f*f)) / ((f*f) - A*c*(s-f))) - ((s*(f*f)) / ((f*f) + A*c*(s-f)))
    // s = subject distance, A = f/stop, c = circle of confusion, f = focal length
    double s = subject_distance*MM_PER_METER; // put subject distance in mm, simplify var name for clarity
    double A = camera.get_lens().get_f_stop(); // simplify var names
    double c = camera.get_circle_of_confusion();
    double f = camera.get_lens().get_focal_length();

    double dof = ((s*(f*f)) / ((f*f) - A*c*(s-f))) - ((s*(f*f)) / ((f*f) + A*c*(s-f)));
    dof /= MM_PER_METER; // put final answer in meters
    // DOF will calculate negative if subject distance is beyond the hyper-focal distance of the lens.
    if (dof > 0) {
        return dof;
    }
    return -1.0;
}

double Photograph::calculate_magnification() {
    // magnification = f / (s-f)
    // f = focal length, s = subject distance
    double s = subject_distance*MM_PER_METER; // convert to mm, simplify var name for clarity
    double f = camera.get_lens().get_focal_length();
    double magnification = f / (s - f);
    return magnification;
}

double Photograph::field_of_view_horizontal() {
    // Horizontal FOV = 2 * ARCTAN( w / (2*f*(m+1)) ) -> convert to degrees
    // w = frame width, f = focal length, m = magnification
    double m = calculate_magnification();
    double w = camera.get_frame_width();
    double f = camera.get_lens().get_focal_length();
    double h_fov = 2 * atan(w / (2*f*(m+1))) * (180.0 / M_PI);
    return h_fov;
}