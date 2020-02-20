//
// Created by Luke on 1/20/2020.
//

#include "Rectilinear_Lens.h"
#include <experimental/optional>
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





// TODO: MOVE DOF FUNCTION TO PHOTOGRAPH CLASS
//double Rectilinear_Lens::depth_of_field(double subject_distance) {
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