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

ostream& operator << (ostream& outs, const Rectilinear_Lens &lens) {
    outs << "Lens Type =\t" << lens.get_type() << endl;
    outs << "Focal Length =\t" << lens.get_focal_length() << " mm" << endl;
    outs << "F/stop =\tf/" << lens.get_f_stop() << endl;
    return outs;
}