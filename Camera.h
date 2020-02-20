//
// Created by Luke on 2/12/2020.
//

#ifndef LF_PROJECT2_CAMERA_H
#define LF_PROJECT2_CAMERA_H

#include "Rectilinear_Lens.h"
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

// the conversion factor between mm and meters
double const MM_PER_METER = 1000;

class Camera {
    typedef optional<string> opt_string;
private:
    /*
     * Fields
     */
    double circle_of_confusion;
    double frame_width;
    double frame_height;
    Rectilinear_Lens lens;

public:
    // Default Constructor
    // Requires: Nothing
    // Modifies: circle_of_confusion, frame_width, frame_height, lens
    // Effects: Sets field(s) to default values
    Camera();

    // Constructor
    // Requires: Three Non-negative, non-zero doubles, and a Rectilinear_Lens object.
    // Modifies: circle_of_confusion, frame_width, frame_height, lens
    // Effects: Sets field(s) to the specified values
    Camera(double circle_of_confusion_, double frame_width_, double frame_height_, const Rectilinear_Lens &lens_);

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns specified field
    double get_circle_of_confusion() const;
    double get_frame_width() const;
    Rectilinear_Lens get_lens() const;
    Rectilinear_Lens & get_lens();
    double get_frame_height() const;

    // Setters
    // Requires: Non-negative, non-zero double, and Rectilinear_Lens object
    // Modifies: The field being set
    // Effects: Sets the field to the specified value
    void set_circle_of_confusion(double circle_of_confusion_);
    void set_frame_height(double frame_height_);
    void set_frame_width(double frame_width_);
    void set_lens(const Rectilinear_Lens &lens_);

    // Requires: Two Camera objects
    // Modifies: nothing
    // Effects: Compares the fields of two Camera objects for equality, and returns true or false.
    friend bool operator == (const Camera &LHS, const Camera &RHS);

    // Requires: ostream, Camera
    // Modifies: nothing
    // Effects: Prints the specifications of the camera.
    friend ostream& operator << (ostream& outs, const Camera &camera);

};


#endif //LF_PROJECT2_CAMERA_H
