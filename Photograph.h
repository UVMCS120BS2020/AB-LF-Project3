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

    // Constructor
    // Requires: camera object, non-zero, non-negative double
    // Modifies: camera, subject_distance
    // Effects: Sets field(s) to the specified values
    Photograph(Camera &camera, double subject_distance);

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns specified field
    Camera get_camera() const;
    Camera & get_camera();
    double get_subject_distance() const;

    // Setters
    // Requires: Non-negative, non-zero double, and Camera object
    // Modifies: The field being set
    // Effects: Sets the field to the specified value
    void set_camera(Camera &camera);
    void set_subject_distance(double subject_distance);

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

    // Requires: Two Photograph objects
    // Modifies: nothing
    // Effects: Compares the fields of two Photograph objects for equality, and returns true or false.
    friend bool operator == (const Photograph &LHS, const Photograph &RHS);

    // Requires: ostream, Photograph
    // Modifies: nothing
    // Effects: Prints the specifications of the photograph.
    friend ostream &operator<<(ostream &os, const Photograph &photograph);
};

#endif //LF_PROJECT2_PHOTOGRAPH_H
