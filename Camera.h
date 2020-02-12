//
// Created by Luke on 2/12/2020.
//

#ifndef LF_PROJECT2_CAMERA_H
#define LF_PROJECT2_CAMERA_H

#include "Lens.h"
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

typedef optional<string> opt_string;

class Camera {
private:
    // Fields
    double circle_of_confusion;
    double frame_width;
    double frame_height;
    Lens lens;

public:
    Camera();
    Camera(double circle_of_confusion_, double frame_width_, double frame_height_, Lens &lens_);

    // GETTERS
    double get_circle_of_confusion() const;
    double get_frame_width() const;
    const Lens &get_lens() const;
    double get_frame_height() const;

    // SETTERS
    void set_circle_of_confusion(double circle_of_confusion);
    void set_frame_height(double frame_height);
    void set_frame_width(double frame_width);
    void set_lens(const Lens &lens);
};


#endif //LF_PROJECT2_CAMERA_H
