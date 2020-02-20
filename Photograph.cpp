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

Camera & Photograph::get_camera() {
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

double Photograph::depth_of_field() const {
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

double Photograph::calculate_magnification() const {
    // magnification = f / (s-f)
    // f = focal length, s = subject distance
    double s = subject_distance*MM_PER_METER; // convert to mm, simplify var name for clarity
    double f = camera.get_lens().get_focal_length();
    double magnification = f / (s - f);
    return magnification;
}

bool operator == (const Photograph &LHS, const Photograph &RHS) {
    return (LHS.get_camera() == RHS.get_camera() &&
            LHS.get_subject_distance() == RHS.get_subject_distance());
}

ostream &operator<<(ostream &outs, const Photograph &photograph) {
    double depth_of_field = photograph.depth_of_field();
    double magnification = photograph.calculate_magnification();
    double field_of_view = photograph.get_camera().get_lens().field_of_view_horizontal(magnification, photograph.camera.get_frame_width());

    outs << "Subj. Dist. =\t" << photograph.subject_distance << " meters" << endl;
    outs << "DOF =\t\t";
    if (depth_of_field >= 0) {
        outs << setprecision(3) << depth_of_field << " meters" << endl;
    } else {
        outs << "infinite (subject is beyond hyper-focal distance)" << endl;
    }
    outs << "Magnification =\t" << setprecision(3) << magnification << " x" << endl;
    outs << "Hor. FOV =\t" << setprecision(3) << field_of_view << " degrees" << endl;
    outs << "Camera:\n" << photograph.get_camera() << endl;
    return outs;
}
