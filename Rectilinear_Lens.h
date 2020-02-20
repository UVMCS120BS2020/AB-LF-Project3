//
// Created by Luke on 1/20/2020.
//
#ifndef LF_PROJECT1_LENS_H
#define LF_PROJECT1_LENS_H

#include <iostream>
#include <iomanip>
#include <experimental/optional>
#include "Lens.h"

using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

class Rectilinear_Lens : public Lens {
    typedef optional<string> opt_string;
public:
    // Default Constructor
    // Requires: Nothing
    // Modifies: f_stop, focal_length, name
    // Effects: Sets field(s) to default values
    Rectilinear_Lens();

    // Constructor
    // Requires: Non-negative, non-zero double, and string optional
    // Modifies: f_stop, focal_length, name
    // Effects: Sets field(s) to the specified values
    Rectilinear_Lens(double focal_length_, double f_stop_, opt_string &name_);

    /*
     * Destructor
     */
    ~Rectilinear_Lens() override = default;

    // Requires: Non-negative double magnification, non-negative double frame_width
    // Modifies: Nothing
    // Effects: Calculates field of view for the lens using frame dimensions, focal length, and object distance (focus distance)
    double field_of_view_horizontal(double magnification, double frame_width) const;


};

#endif //LF_PROJECT1_LENS_H
