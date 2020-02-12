//
// Created by Luke on 1/20/2020.
//

#include "Lens.h"

typedef std::optional<std::string> opt_string;

/********************** Lens class **********************/

Lens::Lens() {

    // the distance between the center of a lens and its focal plane
    focal_length = 50.0;
    // f/stop = focal length (mm) / aperture diameter (mm)
    f_stop = 4.0;
    // Name of the lens, by default nothing.
    name = std::nullopt;

}

Lens::Lens(double focal_length_, double f_stop_, opt_string &name_) {

    this -> focal_length = focal_length_;
    this -> f_stop = f_stop_;
    this -> name = name_;

}

double Lens::get_f_stop() const {
    return f_stop;
}

void Lens::set_f_stop(double f_stop_) {
    this -> f_stop = f_stop_;
}

double Lens::get_focal_length() const {
    return focal_length;
}

void Lens::set_focal_length(double focal_length_) {
    this -> focal_length = focal_length_;
}

opt_string Lens::get_name() const {
    return name;
}

void Lens::set_name(opt_string &name_) {
    this -> name = name_;
}

void Lens::clear_name() {
    name = std::nullopt;
}