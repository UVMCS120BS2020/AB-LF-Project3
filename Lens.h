//
// Created by Luke on 2/12/2020.
//

#ifndef LF_PROJECT2_ABSTRACT_LENS_H
#define LF_PROJECT2_ABSTRACT_LENS_H

#include <iostream>
#include <iomanip>
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

class Lens {
    typedef optional<string> opt_string;
protected:
    /*
     * Fields
     */
    // f/stop = focal length (mm) / aperture diameter (mm)
    double f_stop;
    // the distance between the center of a lens and its focal plane
    double focal_length;
    // Name of the lens, by default nothing.
    opt_string name;

    // Lens type
    enum lens_type {
        rectilinear,
        curvilinear,
        no_type
    };
    lens_type type;

public:

    // Default Constructor
    // Requires: Nothing
    // Modifies: f_stop, focal_length, name
    // Effects: Sets field(s) to default values
    Lens();

    // Constructor
    // Requires: Non-negative, non-zero double, and string optional
    // Modifies: f_stop, focal_length, name
    // Effects: Sets field(s) to the specified values
    Lens(double focal_length_, double f_stop_, opt_string &name_);

    // Virtual Destructor
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Deletes object and deallocates it from memory. Intended to be overridden.
    virtual ~Lens() = 0;

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns specified field
    double get_f_stop() const;
    double get_focal_length() const;
    opt_string get_name() const;

    // Setters
    // Requires: Non-negative, non-zero double, and string optional
    // Modifies: The field being set
    // Effects: Sets the field to the specified value
    void set_f_stop(double f_stop_);
    void set_focal_length(double focal_length_);
    void set_name(opt_string &name_);

    // Requires: Nothing
    // Modifies: name
    // Effects: sets name to nullopt
    void clear_name();

    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns lens type as a string.
    string get_type() const;

    // Requires: Two Lens objects
    // Modifies: nothing
    // Effects: Compares the fields of two Lens objects for equality, and returns true or false.
    friend bool operator == (const Lens &LHS, const Lens &RHS);
};


#endif //LF_PROJECT2_ABSTRACT_LENS_H
