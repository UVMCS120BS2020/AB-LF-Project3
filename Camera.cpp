//
// Created by Luke on 2/12/2020.
//

#include "Camera.h"

Camera::Camera() {
    // This is a measure of maximum sharpness. It refers to the physical area (mm) on a focal plane where a point of light
    // is most in focus, ie the maximum sharpness of a point of light when cast through a lens onto a focal plane.
    circle_of_confusion = 0.02;
    // This is a measure of the sensor or film width in millimeters. 36mm is the height of a standard 35mm film frame.
    frame_width = 36.0;
    // This is a measure of the sensor or film height in millimeters. 24mm is the height of a standard 35mm film frame.
    frame_height = 24.0;
    // make default lens
    Rectilinear_Lens default_lens = Rectilinear_Lens();
    lens = default_lens;
}

Camera::Camera(double circle_of_confusion_, double frame_width_, double frame_height_, const Rectilinear_Lens &lens_) {
    this -> circle_of_confusion = circle_of_confusion_;
    this -> frame_width = frame_width_;
    this -> frame_height = frame_height_;
    this -> lens = lens_;
}

double Camera::get_circle_of_confusion() const {
    return circle_of_confusion;
}

void Camera::set_circle_of_confusion(double circle_of_confusion_) {
    Camera::circle_of_confusion = circle_of_confusion_;
}

double Camera::get_frame_width() const {
    return frame_width;
}

void Camera::set_frame_width(double frame_width_) {
    Camera::frame_width = frame_width_;
}

double Camera::get_frame_height() const {
    return frame_height;
}

void Camera::set_frame_height(double frame_height_) {
    Camera::frame_height = frame_height_;
}

Rectilinear_Lens Camera::get_lens() const {
    return lens;
}

Rectilinear_Lens & Camera::get_lens() {
    return lens;
}

void Camera::set_lens(const Rectilinear_Lens &lens_) {
    Camera::lens = lens_;
}


