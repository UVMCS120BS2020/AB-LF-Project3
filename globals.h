//
// Created by Luke on 2/4/2020.
//

#ifndef LF_PROJECT2_GLOBALS_H
#define LF_PROJECT2_GLOBALS_H

#include "Lens.h"


// Requires: A valid Lens object, A non-negative, non-zero double (subject distance in meters),
//              where the subject distance (m) is greater than the lens length (mm)
// Modifies: Nothing
// Effects: Calculates magnification using focal length and object distance (focus distance)
double calculate_magnification(Lens const &lens, double subject_distance);

// Requires: A valid Lens object, A non-negative non-zero double
// Modifies: Nothing
// Effects: Calculates field of view for the lens using frame dimensions, focal length, and object distance (focus distance)
double field_of_view_horizontal(Lens const &lens, double magnification);

#endif //LF_PROJECT2_GLOBALS_H
