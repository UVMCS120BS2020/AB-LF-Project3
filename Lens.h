//
// Created by Luke on 1/20/2020.
//

#include <optional>
#include <iostream>
#include <iomanip>

#ifndef LF_PROJECT1_LENS_H
#define LF_PROJECT1_LENS_H

using namespace std;

typedef std::optional<std::string> opt_string;

class Lens {
private:
    // Fields
    double f_stop;
    double focal_length;
    opt_string name;

public:
    // Constructor
    Lens();
    Lens(double focal_length_, double f_stop_, opt_string &name_);


    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns specified field
    double get_f_stop() const;
    double get_focal_length() const;
    opt_string get_name() const;

    // Setters
    // Requires: A non-negative, non-zero double
    // Modifies: The field being set
    // Effects: Sets the field to the specified value
    void set_f_stop(double f_stop_);
    void set_focal_length(double focal_length_);
    void set_name(opt_string &name_);

    // Requires: Nothing
    // Modifies: name
    // Effects: sets name to nullopt
    void clear_name();
};

#endif //LF_PROJECT1_LENS_H
