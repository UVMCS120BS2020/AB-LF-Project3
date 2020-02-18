//
// Created by Luke on 1/20/2020.
//
#ifndef LF_PROJECT1_LENS_H
#define LF_PROJECT1_LENS_H

#include <iostream>
#include <iomanip>
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

class Lens {
    typedef optional<string> opt_string;
private:
    // Fields
    double f_stop;
    double focal_length;
    opt_string name;

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

    /*
     * Overloaded Operator(s)
     */
    friend bool operator == (const Lens &LHS, const Lens &RHS) {
        return (LHS.get_focal_length() == RHS.get_focal_length() &&
                LHS.get_f_stop() == RHS.get_f_stop() &&
                LHS.get_name() == RHS.get_name());
    }
};

#endif //LF_PROJECT1_LENS_H
