//
// Created by Luke on 2/12/2020.
//

#ifndef LF_PROJECT2_PHOTOGRAPH_H
#define LF_PROJECT2_PHOTOGRAPH_H


#include "Camera.h"

class Photograph {
private:
    // Fields
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
    //              where the subject distance (m) is greater than the lens length (mm)
    // Modifies: Nothing
    // Effects: Calculates magnification using focal length and object distance (focus distance)
    double calculate_magnification() const;

    // Requires: A valid Rectilinear_Lens object, A non-negative non-zero double
    // Modifies: Nothing
    // Effects: Calculates field of view for the lens using frame dimensions, focal length, and object distance (focus distance)
    double field_of_view_horizontal() const;

    friend bool operator == (const Photograph &LHS, const Photograph &RHS) {
        return (LHS.get_camera() == RHS.get_camera() &&
                LHS.get_subject_distance() == RHS.get_subject_distance());
    }

    // Requires: ostream, Camera
    // Modifies: nothing
    // Effects: Prints the specifications of the lens.
    friend ostream& operator << (ostream& outs, const Photograph &photograph) {
        outs << "Subj. Dist. =\t" << photograph.subject_distance << " meters" << endl;
        outs << "DOF =\t\t";
        if (photograph.depth_of_field() >= 0) {
            outs << setprecision(3) << photograph.depth_of_field() << " meters" << endl;
        } else {
            outs << "infinite (subject is beyond hyper-focal distance)" << endl;
        }
        outs << "Magnification =\t" << setprecision(3) << photograph.calculate_magnification() << " x" << endl;
        outs << "Hor. FOV =\t" << setprecision(3) << photograph.field_of_view_horizontal() << " degrees" << endl;
        outs << "Camera:\n" << photograph.get_camera() << endl;
        return outs;
    }
};

#endif //LF_PROJECT2_PHOTOGRAPH_H
