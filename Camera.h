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
    // Fields
    double circle_of_confusion;
    double frame_width;
    double frame_height;
    Rectilinear_Lens lens;

public:
    Camera();
    Camera(double circle_of_confusion_, double frame_width_, double frame_height_, const Rectilinear_Lens &lens_);

    // GETTERS
    double get_circle_of_confusion() const;
    double get_frame_width() const;
    Rectilinear_Lens get_lens() const;
    Rectilinear_Lens & get_lens();
    double get_frame_height() const;

    // SETTERS
    void set_circle_of_confusion(double circle_of_confusion_);
    void set_frame_height(double frame_height_);
    void set_frame_width(double frame_width_);
    void set_lens(const Rectilinear_Lens &lens_);

    friend bool operator == (const Camera &LHS, const Camera &RHS) {
        return (LHS.get_circle_of_confusion() == RHS.get_circle_of_confusion() &&
                LHS.get_frame_width() == RHS.get_frame_width() &&
                LHS.get_frame_height() == RHS.get_frame_height() &&
                LHS.get_lens() == RHS.get_lens());
    }

    // Requires: ostream, Camera
    // Modifies: nothing
    // Effects: Prints the specifications of the lens.
    friend ostream& operator << (ostream& outs, const Camera &camera) {
        outs << "CoC =\t\t" << camera.get_circle_of_confusion() << " mm" << endl;
        outs << "Frame Width =\t" << camera.get_frame_width() << " mm" << endl;
        outs << "Frame Height =\t" << camera.get_frame_height() << " mm" << endl;
        outs << "Lens:\n" << camera.get_lens() << endl;
        return outs;
    }

};


#endif //LF_PROJECT2_CAMERA_H
