//
// Created by Luke on 2/12/2020.
//

#include "Lens.h"
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

typedef optional<string> opt_string;

/********************** Lens class **********************/

Lens::Lens() : focal_length(50.0), f_stop(4.0), name(nullopt) {}

Lens::Lens(double focal_length_, double f_stop_, opt_string &name_) : focal_length(focal_length_), f_stop(f_stop_), name(name_) {}

Lens::~Lens() = default;

double Lens::get_f_stop() const {
    return f_stop;
}
double Lens::get_focal_length() const {
    return focal_length;
}
opt_string Lens::get_name() const {
    return name;
}

void Lens::set_f_stop(double f_stop_) {
    f_stop = f_stop_;
}
void Lens::set_focal_length(double focal_length_) {
    focal_length = focal_length_;
}
void Lens::set_name(opt_string &name_) {
    name = name_;
}

void Lens::clear_name() {
    name = nullopt;
}

string Lens::get_type() const {
    switch (type) {
        case rectilinear: return "Rectilinear";
        case curvilinear: return "Curvilinear";
        case no_type: return "No Type";
    }
    return "";
}

bool operator == (const Lens &LHS, const Lens &RHS) {
    return (LHS.get_focal_length() == RHS.get_focal_length() &&
            LHS.get_f_stop() == RHS.get_f_stop() &&
            LHS.get_name() == RHS.get_name() &&
            LHS.get_type() == RHS.get_type());
}

