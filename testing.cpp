//
// Created by Luke on 2/5/2020.
//

#include <cmath>
#include <iostream>
#include <optional>
#include "Lens.h"
#include "globals.h"

typedef std::optional<std::string> opt_string;

bool test_lens();
bool test_lens_helper(Lens &lens, double e_focal_length, double e_f_stop, double e_circle_of_confusion,
                      double e_frame_width, double e_frame_height, opt_string e_name);
bool test_dof();
bool test_dof_helper(Lens &lens, double subject_distance, double e_dof);
bool test_magnification();
bool test_magnification_helper(Lens &lens, double subject_distance, double e_mag);
bool test_fov();
bool test_fov_helper(Lens &lens, double subject_distance, double e_fov);


int main() {
    if (test_lens()) {
        std::cout << "Lens Test Passed." << std::endl;
    }
    if (test_dof()) {
        std::cout << "DOF Test Passed." << std::endl;
    }
    if (test_magnification()) {
        std::cout << "Magnification Test Passed." << std::endl;
    }
    if (test_fov()) {
        std::cout << "FOV Test Passed." << std::endl;
    }
}

bool test_lens() {
    double new_focal_length = 51.0;
    double new_f_stop = 5.0;
    double new_circle_of_confusion = 0.03;
    double new_frame_width = 30.0;
    double new_frame_height = 20.0;
    opt_string new_name = "Lens1";

    // test default constructor and all setters
    Lens lens1 = Lens();
    if (!test_lens_helper(lens1, 50.0, 4.0, 0.02, 36.0, 24.0, std::nullopt)) {
        std::cout << "\nTest case failed: Default Constructor" << std::endl;
        return false;
    }
    lens1.set_focal_length(new_focal_length);
    if (!test_lens_helper(lens1, new_focal_length, 4.0, 0.02, 36.0, 24.0, std::nullopt)) {
        std::cout << "\nTest case failed: focal_length Setter" << std::endl;
        return false;
    }
    lens1.set_f_stop(new_f_stop);
    if (!test_lens_helper(lens1, new_focal_length, new_f_stop, 0.02, 36.0, 24.0, std::nullopt)) {
        std::cout << "\nTest case failed: f_stop setter" << std::endl;
        return false;
    }
    lens1.set_circle_of_confusion(new_circle_of_confusion);
    if (!test_lens_helper(lens1, new_focal_length, new_f_stop, new_circle_of_confusion, 36.0, 24.0, std::nullopt)) {
        std::cout << "\nTest case failed: circle_of_confusion setter" << std::endl;
        return false;
    }
    lens1.set_frame_width(new_frame_width);
    if (!test_lens_helper(lens1, new_focal_length, new_f_stop, new_circle_of_confusion, new_frame_width, 24.0, std::nullopt)) {
        std::cout << "\nTest case failed: frame_width setter" << std::endl;
        return false;
    }
    lens1.set_frame_height(new_frame_height);
    if (!test_lens_helper(lens1, new_focal_length, new_f_stop, new_circle_of_confusion, new_frame_width, new_frame_height, std::nullopt)) {
        std::cout << "\nTest case failed: frame_height setter" << std::endl;
        return false;
    }
    lens1.set_name(new_name);
    if (!test_lens_helper(lens1, new_focal_length, new_f_stop, new_circle_of_confusion, new_frame_width, new_frame_height, new_name)) {
        std::cout << "\nTest case failed: name setter" << std::endl;
        return false;
    }
    // test non-default constructor
    Lens lens2 = Lens(new_focal_length, new_f_stop, new_circle_of_confusion, new_frame_width, new_frame_height, new_name);
    if (!test_lens_helper(lens2, new_focal_length, new_f_stop, new_circle_of_confusion, new_frame_width, new_frame_height, new_name)) {
        std::cout << "\nTest case failed: non-default constructor" << std::endl;
        return false;
    }
    // test clear_name()
    lens2.clear_name();
    if (!test_lens_helper(lens2, new_focal_length, new_f_stop, new_circle_of_confusion, new_frame_width, new_frame_height, std::nullopt)) {
        std::cout << "\nTest case failed: clear_name()" << std::endl;
        return false;
    }
    return true;
}

bool test_lens_helper(Lens &lens, double e_focal_length, double e_f_stop, double e_circle_of_confusion,
        double e_frame_width, double e_frame_height, opt_string e_name) {
    // return true if all values are expected
    return (lens.get_focal_length() == e_focal_length && lens.get_f_stop() == e_f_stop &&
             lens.get_circle_of_confusion() == e_circle_of_confusion && lens.get_frame_width() == e_frame_width &&
             lens.get_frame_height() == e_frame_height && lens.get_name() == e_name);
}

bool test_dof() {
    // expected values from https://www.dofmaster.com/dofjs.html
    Lens lens1 = Lens(); // focal_length = 50mm, f_stop = 4.0, CoC = 0.02

    // 50mm lens, 5m subject distance, 4.0 f/stop, 0.02mm CoC
    if (!test_dof_helper(lens1, 5.0, 1.62)) {
        return false;
    }

    // 50mm lens, 25m subject distance, 4.0 f/stop, 0.02mm CoC
    if (!test_dof_helper(lens1, 25.0, 110.1)) {
        return false;
    }

    // 100mm lens, 5m subject distance, 4.0 f/stop, 0.02mm CoC
    lens1.set_focal_length(100.0);
    if (!test_dof_helper(lens1, 5.0, 0.39)) {
        return false;
    }

    // 50mm lens, 5m subject distance, 1.4 f/stop, 0.02mm CoC
    lens1.set_focal_length(50);
    lens1.set_f_stop(1.4);
    if (!test_dof_helper(lens1, 5.0, 0.56)) {
        return false;
    }

    // 50mm lens, 33m subject distance, 4.0 f/stop, 0.02mm CoC (hyper-focal distance of 32.3m)
    lens1.set_f_stop(4.0);
    if (!test_dof_helper(lens1, 33.0, -1)) {
        return false;
    }

    // 50mm lens, 33m subject distance, f/stop 22.0, 0.02mm CoC (hyper-focal distance of 5.57m)
    lens1.set_f_stop(22.0);
    if (!test_dof_helper(lens1, 6.0, -1)) {
        return false;
    }


    return true;
}

bool test_dof_helper(Lens &lens, double subject_distance, double e_dof) {
    double dof = lens.depth_of_field(subject_distance);
    // 0.1 meter tolerance
    const double TOLERANCE = 0.1;
    if (fabs(dof - e_dof) > TOLERANCE) {
        std::cout << "\nTest case failed: DOF. \n\tfocal length = " << lens.get_focal_length() <<
                    "\n\tf stop = " << lens.get_f_stop() << "\n\tCoC = " << lens.get_circle_of_confusion() <<
                    "\n\tsubject distance = " << subject_distance << "\n\tDOF = " << dof << "\n\te_DOF = " << e_dof << std::endl;
        return false;
    }
    return true;
}

bool test_magnification() {
    // expected values from https://www.kielia.de/photography/calculator/
    Lens lens1 = Lens(); // focal_length = 50mm

    // standard focal length (50mm), 5m subject distance
    if (!test_magnification_helper(lens1, 5.0, 0.01)) {
        return false;
    }

    // standard focal length, 1m subject distance
    if (!test_magnification_helper(lens1, 1.0, 0.06)) {
        return false;
    }

    // longer focal length, 5m subject distance
    lens1.set_focal_length(200.0);
    if (!test_magnification_helper(lens1, 5.0, 0.04)) {
        return false;
    }

    // shorter focal length, 5m subject distance
    lens1.set_focal_length(20);
    if (!test_magnification_helper(lens1, 5.0, 0.0)) {
        return false;
    }

    // really small focal length, 5m subject distance
    lens1.set_focal_length(0.001);
    if (!test_magnification_helper(lens1, 5.0, 0.0)) {
        return false;
    }

    // really large focal length, very far subject (focused to infinity)
    lens1.set_focal_length(1000000.0);
    if (!test_magnification_helper(lens1, 1000000000.0, 0)) {
        return false;
    }

    // really large focal length, close subject (1mm from lens)
    if (!test_magnification_helper(lens1, 1000.01, 100000.0)) {
        return false;
    }


    return true;
}

bool test_magnification_helper(Lens &lens, double subject_distance, double e_mag){
    double mag = calculate_magnification(lens, subject_distance);
    // 0.01 tolerance
    const double TOLERANCE = 0.01;
    if (fabs(mag - e_mag) > TOLERANCE) {
        std::cout << "\nTest case failed: Magnification. \n\tfocal length = " << lens.get_focal_length() <<
                  "\n\tsubject distance = " << subject_distance << "\n\tmag = " << mag << "\n\te_mag = " << e_mag << std::endl;
        return false;
    }
    return true;
}

bool test_fov() {
    // expected values from https://www.pointsinfocus.com/tools/depth-of-field-and-equivalent-lens-calculator/
    Lens lens1 = Lens(); // focal_length = 50mm, frame_width = 36mm

    // standard focal length, standard frame size
    if (!test_fov_helper(lens1, 5.0, 39.2)) {
        return false;
    }

    // longer focal length, standard frame size
    lens1.set_focal_length(100);
    if (!test_fov_helper(lens1, 5.0, 20.0)) {
        return false;
    }

    // really short lens
    lens1.set_focal_length(0.001);
    if (!test_fov_helper(lens1, 5.0, 180.0)) {
        return false;
    }

    // really long lens (subject must be farther away than lens length)
    lens1.set_focal_length(1000000.0);
    if (!test_fov_helper(lens1, 1000000.0, 0.0)) {
        return false;
    }

    // slightly larger frame, standard lens
    lens1.set_focal_length(50);
    lens1.set_frame_width(50);
    if (!test_fov_helper(lens1, 5.0, 52.7)) {
        return false;
    }

    // really small frame
    lens1.set_frame_width(0.001);
    if (!test_fov_helper(lens1, 5.0, 0.0)) {
        return false;
    }

    // really big frame
    lens1.set_frame_width(100000000.0);
    if (!test_fov_helper(lens1, 5.0, 180.0)) {
        return false;
    }


    return true;
}

bool test_fov_helper(Lens &lens, double subject_distance, double e_fov) {
    double mag = calculate_magnification(lens, subject_distance);
    double fov = field_of_view_horizontal(lens, mag);
    // 0.1 tolerance
    const double TOLERANCE = 0.1;
    if (fabs(fov - e_fov) > TOLERANCE) {
        std::cout << "\nTest case failed: FOV. \n\tfocal length = " << lens.get_focal_length() <<
                "\n\tframe width = " << lens.get_frame_width() <<
                "\n\tmag = " << mag <<
                "\n\tfov = " << fov << "\n\te_fov = " << e_fov << std::endl;
        return false;
    }
    return true;
}