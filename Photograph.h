//
// Created by Luke on 2/12/2020.
//

#ifndef LF_PROJECT2_PHOTOGRAPH_H
#define LF_PROJECT2_PHOTOGRAPH_H

#include <ostream>
#include "Camera.h"

class Photograph {
private:
    /*
     * Fields
     */
    Camera camera;
    double subject_distance;
public:
    constexpr static const double MM_PER_METER = 1000;

    Photograph(Camera &camera, double subject_distance);

    Camera get_camera() const;
    Camera & get_camera();
    double get_subject_distance() const;

    void set_camera(Camera &camera);
    void set_subject_distance(double subject_distance);

public:
    // Requires: A non-negative, non-zero double, which is greater than the focal length in mm of the lens.
    // Modifies: Nothing
    // Effects: Calculates the total depth of field (the depth of a 3-dimensional area of space which is appropriately in focus)
    //          If subject distance is beyond the hyper-focal distance of the lens, the DOF is infinite, and the function will return -1.
    double depth_of_field() const;

    // Requires: A valid Rectilinear_Lens object, A non-negative, non-zero double (subject distance in meters),
    //           where the subject distance (m) is greater than the lens length (mm)
    // Modifies: Nothing
    // Effects: Calculates magnification using focal length and object distance (focus distance)
    double calculate_magnification() const;

    friend bool operator == (const Photograph &LHS, const Photograph &RHS);

    friend ostream &operator<<(ostream &os, const Photograph &photograph);
};

#endif //LF_PROJECT2_PHOTOGRAPH_H
