//
// Created by Luke on 2/5/2020.
//

#include <cmath>
#include <iostream>
#include "Rectilinear_Lens.h"
#include "Camera.h"
#include "Photograph.h"
#include <experimental/optional>
using experimental::optional;
using experimental::nullopt;
using experimental::make_optional;
using namespace std;

typedef optional<string> opt_string;


/********************** Testing Functions Declarations **********************/

bool test_photograph();
bool test_photograph_helper(Photograph &photograph, Camera &camera, double e_subject_distance);
bool test_camera();
bool test_camera_helper(Camera &camera, double e_circle_of_confusion,
                        double e_frame_width, double e_frame_height, const Rectilinear_Lens& e_lens);
bool test_lens();
bool test_lens_helper(Rectilinear_Lens &lens, double e_focal_length, double e_f_stop, const opt_string& e_name);
bool test_dof();
bool test_dof_helper(Photograph &photograph, double e_dof);
bool test_magnification();
bool test_magnification_helper(Photograph &photograph, double e_mag);
bool test_fov();
bool test_fov_helper(Photograph &photograph, double e_fov);


int main() {
    if (test_lens()) {
        cout << "Rectilinear_Lens Test Passed." << endl;
    }
    if (test_camera()) {
        cout << "Camera Test Passed." << endl;
    }
    if (test_photograph()) {
        cout << "Photograph Test Passed." << endl;
    }
    return 0;
}


/********************** Testing Functions Definitions **********************/


// test constructor and getters/setters of Rectilinear_Lens class
bool test_lens() {
    //typedef optional<string> opt_string;

    double default_focal_length = 50.0;
    double default_f_stop = 4.0;
    opt_string default_name = nullopt;
    double new_focal_length = 51.0;
    double new_f_stop = 5.0;
    opt_string new_name = "Lens1";

    // test default constructor
    Rectilinear_Lens lens1 = Rectilinear_Lens();
    if (!test_lens_helper(lens1, default_focal_length, default_f_stop, nullopt)) {
        cout << "\nTest case failed: Default Constructor" << endl;
        return false;
    }
    // test set focal length
    lens1.set_focal_length(new_focal_length);
    if (!test_lens_helper(lens1, new_focal_length, default_f_stop, nullopt)) {
        cout << "\nTest case failed: focal_length Setter" << endl;
        return false;
    }
    // test set f stop
    lens1.set_f_stop(new_f_stop);
    if (!test_lens_helper(lens1, new_focal_length, new_f_stop, nullopt)) {
        cout << "\nTest case failed: f_stop setter" << endl;
        return false;
    }
    // test set name
    lens1.set_name(new_name);
    if (!test_lens_helper(lens1, new_focal_length, new_f_stop, new_name)) {
        cout << "\nTest case failed: name setter" << endl;
        return false;
    }
    // test clear_name()
    lens1.clear_name();
    if (!test_lens_helper(lens1, new_focal_length, new_f_stop,  nullopt)) {
        cout << "\nTest case failed: clear_name()" << endl;
        return false;
    }
    // test non-default constructor
    Rectilinear_Lens lens2 = Rectilinear_Lens(new_focal_length, new_f_stop, new_name);
    if (!test_lens_helper(lens2, new_focal_length, new_f_stop, new_name)) {
        cout << "\nTest case failed: non-default constructor" << endl;
        return false;
    }
    return true;
}

bool test_lens_helper(Rectilinear_Lens &lens, double e_focal_length, double e_f_stop, const opt_string& e_name) {
    // return true if all values are expected
    return (lens.get_focal_length() == e_focal_length && lens.get_f_stop() == e_f_stop &&
             lens.get_name() == e_name);
}


// test constructor and getters/setters of Camera class
bool test_camera() {
    double default_circle_of_confusion = 0.02;
    double default_frame_width = 36.0;
    double default_frame_height = 24.0;

    double new_circle_of_confusion = 0.03;
    double new_frame_width = 30.0;
    double new_frame_height = 20.0;

    Camera camera1 = Camera();

    // for constructing new lens
    double new_focal_length = 51.0;
    double new_f_stop = 5.0;
    opt_string new_name = "Lens1";
    Rectilinear_Lens new_lens = Rectilinear_Lens();

    // test default constructor
    if (!test_camera_helper(camera1, default_circle_of_confusion, default_frame_width, default_frame_height, camera1.get_lens())) {
        cout << "\nTest case failed: Default Constructor" << endl;
        return false;
    }
    //test CoC
    camera1.set_circle_of_confusion(new_circle_of_confusion);
    if (!test_camera_helper(camera1, new_circle_of_confusion, default_frame_width, default_frame_height, camera1.get_lens())) {
        cout << "\nTest case failed: circle_of_confusion setter" << endl;
        return false;
    }
    //test frame width
    camera1.set_frame_width(new_frame_width);
    if (!test_camera_helper(camera1, new_circle_of_confusion, new_frame_width, default_frame_height, camera1.get_lens())) {
        cout << "\nTest case failed: frame_width setter" << endl;
        return false;
    }
    //test frame height
    camera1.set_frame_height(new_frame_height);
    if (!test_camera_helper(camera1, new_circle_of_confusion, new_frame_width, new_frame_height, camera1.get_lens())) {
        cout << "\nTest case failed: frame_height setter" << endl;
        return false;
    }
    //test lens
    camera1.set_lens(new_lens);
    if (!test_camera_helper(camera1, new_circle_of_confusion, new_frame_width, new_frame_height, camera1.get_lens())) {
        cout << "\nTest case failed: Rectilinear_Lens setter" << endl;
        return false;
    }
    // test non-default constructor
    Camera camera2 = Camera(new_circle_of_confusion, new_frame_width, new_frame_height, new_lens);
    if (!test_camera_helper(camera2, new_circle_of_confusion, new_frame_width, new_frame_height, camera2.get_lens())) {
        cout << "\nTest case failed: non-default constructor" << endl;
        return false;
    }
    return true;
}

// compares expected to actual values for Camera object
bool test_camera_helper(Camera &camera, double e_circle_of_confusion,
                        double e_frame_width, double e_frame_height, const Rectilinear_Lens& e_lens) {
    // return true if all values are expected
    return (camera.get_circle_of_confusion() == e_circle_of_confusion && camera.get_frame_width() == e_frame_width &&
            camera.get_frame_height() == e_frame_height && camera.get_lens() == e_lens);
}



// tests constructor and getters/setters of the Photograph class
bool test_photograph() {
    Camera camera1 = Camera();
    double subject_distance1 = 5.0;

    // test constructor
    Photograph photograph1 = Photograph(camera1, subject_distance1);
    if (!test_photograph_helper(photograph1, camera1, subject_distance1)) {
        cout << "\nTest case failed: constructor" << endl;
        return false;
    }

    // test camera getter/setter
    Camera camera2 = Camera();
    double new_circle_of_confusion = 0.03;
    camera2.set_circle_of_confusion(new_circle_of_confusion);
    photograph1.set_camera(camera2);
    if (!test_photograph_helper(photograph1, camera2, subject_distance1)) {
        cout << "\nTest case failed: camera setter" << endl;
        return false;
    }

    // test subject distance getter/setter
    double new_subject_distance = 10.0;
    photograph1.set_subject_distance(new_subject_distance);
    if (!test_photograph_helper(photograph1, camera2, new_subject_distance)) {
        cout << "\nTest case failed: subject distance setter" << endl;
        return false;
    }

    if (!test_dof()) {
        cout << "\nTest Failed: DOF" << endl;
        return false;
    }

    if (!test_magnification()) {
        cout << "\nTest Failed: Magnification" << endl;
        return false;
    }

    if (!test_fov()) {
        cout << "\nTest Failed: FOV" << endl;
        return false;
    }

    return true;
}

bool test_photograph_helper(Photograph &photograph, Camera &e_camera, double e_subject_distance) {
    // return true if all values are expected
    return (photograph.get_camera() == e_camera && photograph.get_subject_distance() == e_subject_distance);
}


bool test_dof() {
    // expected values from https://www.dofmaster.com/dofjs.html
    Rectilinear_Lens lens1 = Rectilinear_Lens(); // focal_length = 50mm, f_stop = 4.0, CoC = 0.02
    Camera camera1 = Camera();
    camera1.set_lens(lens1);
    double default_subject_distance = 5.0;
    Photograph photograph1 = Photograph(camera1, default_subject_distance);

    // 50mm lens, 5m subject distance, 4.0 f/stop, 0.02mm CoC
    if (!test_dof_helper(photograph1, 1.62)) {
        return false;
    }

    // 50mm lens, 25m subject distance, 4.0 f/stop, 0.02mm CoC
    photograph1.set_subject_distance(25.0);
    if (!test_dof_helper(photograph1, 110.1)) {
        return false;
    }

    // 100mm lens, 5m subject distance, 4.0 f/stop, 0.02mm CoC

    photograph1.get_camera().get_lens().set_focal_length(100.0);
    photograph1.set_subject_distance(5.0);
    if (!test_dof_helper(photograph1, 0.39)) {
        return false;
    }

    // 50mm lens, 5m subject distance, 1.4 f/stop, 0.02mm CoC
    photograph1.get_camera().get_lens().set_focal_length(50);
    photograph1.get_camera().get_lens().set_f_stop(1.4);
    if (!test_dof_helper(photograph1, 0.56)) {
        return false;
    }

    // 50mm lens, 33m subject distance, 4.0 f/stop, 0.02mm CoC (hyper-focal distance of 32.3m)
    photograph1.get_camera().get_lens().set_f_stop(4.0);
    photograph1.set_subject_distance(33.0);
    if (!test_dof_helper(photograph1, -1)) {
        return false;
    }

    // 50mm lens, 33m subject distance, f/stop 22.0, 0.02mm CoC (hyper-focal distance of 5.57m)
    photograph1.get_camera().get_lens().set_f_stop(22.0);
    photograph1.set_subject_distance(6.0);
    if (!test_dof_helper(photograph1, -1)) {
        return false;
    }
    return true;
}

bool test_dof_helper(Photograph &photograph,  double e_dof) {
    double dof = photograph.depth_of_field();
    double subject_distance = photograph.get_subject_distance();
    Camera camera = photograph.get_camera();
    Rectilinear_Lens lens = camera.get_lens();
    // 0.1 meter tolerance
    const double TOLERANCE = 0.1;
    if (fabs(dof - e_dof) > TOLERANCE) {
        cout << "\nTest case failed: DOF. \n\tfocal length = " << lens.get_focal_length() <<
                    "\n\tf stop = " << lens.get_f_stop() <<
                    "\n\tCoC = " << camera.get_circle_of_confusion() <<
                    "\n\tsubject distance = " << subject_distance <<
                    "\n\tDOF = " << dof <<
                    "\n\te_DOF = " << e_dof << endl;
        return false;
    }
    return true;
}

bool test_magnification() {
    // expected values from https://www.kielia.de/photography/calculator/
    Rectilinear_Lens lens1 = Rectilinear_Lens(); // focal_length = 50mm, f_stop = 4.0, CoC = 0.02
    Camera camera1 = Camera();
    camera1.set_lens(lens1);
    double default_subject_distance = 5.0;
    Photograph photograph1 = Photograph(camera1, default_subject_distance);

    // standard focal length (50mm), 5m subject distance
    if (!test_magnification_helper(photograph1, 0.01)) {
        return false;
    }

    // standard focal length, 1m subject distance
    photograph1.set_subject_distance(1.0);
    if (!test_magnification_helper(photograph1, 0.06)) {
        return false;
    }

    // longer focal length, 5m subject distance
    photograph1.get_camera().get_lens().set_focal_length(200.0);
    photograph1.set_subject_distance(5.0);
    if (!test_magnification_helper(photograph1, 0.04)) {
        return false;
    }

    // shorter focal length, 5m subject distance
    photograph1.get_camera().get_lens().set_focal_length(20);
    if (!test_magnification_helper(photograph1, 0.0)) {
        return false;
    }

    // really small focal length, 5m subject distance
    photograph1.get_camera().get_lens().set_focal_length(0.001);
    if (!test_magnification_helper(photograph1, 0.0)) {
        return false;
    }

    // really large focal length, very far subject (focused to infinity)
    photograph1.get_camera().get_lens().set_focal_length(1000000.0);
    photograph1.set_subject_distance(1000000000.0);
    if (!test_magnification_helper(photograph1, 0.0)) {
        return false;
    }

    // really large focal length, close subject (1mm from lens)
    photograph1.set_subject_distance(1000.01);
    if (!test_magnification_helper(photograph1, 100000.0)) {
        return false;
    }

    return true;
}

bool test_magnification_helper(Photograph &photograph, double e_mag){
    double subject_distance = photograph.get_subject_distance();
    double mag = photograph.calculate_magnification();
    Rectilinear_Lens lens = photograph.get_camera().get_lens();
    // 0.01 tolerance
    const double TOLERANCE = 0.01;
    if (fabs(mag - e_mag) > TOLERANCE) {
        cout << "\nTest case failed: Magnification. \n\tfocal length = " << lens.get_focal_length() <<
                  "\n\tsubject distance = " << subject_distance << "\n\tmag = " << mag << "\n\te_mag = " << e_mag << endl;
        return false;
    }
    return true;
}

bool test_fov() {
    // expected values from https://www.pointsinfocus.com/tools/depth-of-field-and-equivalent-lens-calculator/
    Rectilinear_Lens lens1 = Rectilinear_Lens(); // focal_length = 50mm
    Camera camera1 = Camera(); // frame_width = 36mm
    camera1.set_lens(lens1);
    double default_subject_distance = 5.0;
    Photograph photograph1 = Photograph(camera1, default_subject_distance);

    // standard focal length, standard frame size
    if (!test_fov_helper(photograph1, 39.2)) {
        return false;
    }

    // longer focal length, standard frame size
    photograph1.get_camera().get_lens().set_focal_length(100);
    if (!test_fov_helper(photograph1, 20.0)) {
        return false;
    }

    // really short lens
    photograph1.get_camera().get_lens().set_focal_length(0.001);
    if (!test_fov_helper(photograph1, 180.0)) {
        return false;
    }

    // really long lens (subject must be farther away than lens length)
    photograph1.get_camera().get_lens().set_focal_length(1000000.0);
    photograph1.set_subject_distance(1000000.0);
    if (!test_fov_helper(photograph1, 0.0)) {
        return false;
    }

    // slightly larger frame, standard lens
    photograph1.get_camera().get_lens().set_focal_length(50);
    photograph1.set_subject_distance(5.0);
    photograph1.get_camera().set_frame_width(50);
    if (!test_fov_helper(photograph1, 52.7)) {
        return false;
    }

    // really small frame
    photograph1.get_camera().set_frame_width(0.001);
    if (!test_fov_helper(photograph1, 0.0)) {
        return false;
    }

    // really big frame
    photograph1.get_camera().set_frame_width(100000000.0);
    if (!test_fov_helper(photograph1, 180.0)) {
        return false;
    }

    return true;
}

bool test_fov_helper(Photograph &photograph, double e_fov) {
    Camera camera = photograph.get_camera();
    Rectilinear_Lens lens = camera.get_lens();
    double mag = photograph.calculate_magnification();
    double fov = photograph.get_camera().get_lens().field_of_view_horizontal(mag, camera.get_frame_width());
    // 0.1 tolerance
    const double TOLERANCE = 0.1;
    if (fabs(fov - e_fov) > TOLERANCE) {
        cout << "\nTest case failed: FOV. \n\tfocal length = " << lens.get_focal_length() <<
                "\n\tframe width = " << camera.get_frame_width() <<
                "\n\tmag = " << mag <<
                "\n\tfov = " << fov << "\n\te_fov = " << e_fov << endl;
        return false;
    }
    return true;
}