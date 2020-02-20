#include <iostream>
#include <algorithm>
#include "Rectilinear_Lens.h"
#include "Camera.h"
#include "Photograph.h"
#include <experimental/optional>

using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

typedef optional<string> opt_string;


/******************** Global function prototypes ***********************/

// Requires: Nothing
// Modifies: cin, cout
// Effects: Prompts user for non-neg double input using custom message, returns validated input
double prompt_user_for_positive_double(const string &message, const string &error_message);

// Requires: Nothing
// Modifies: cin, cout
// Effects: Prompts user for a string, returns a validated input
string prompt_user_for_string(const string &message, const string &error_message);

// Requires: Nothing
// Modifies: cin, cout
// Effects: Prompts user for 'y' or 'n', returns true if 'y', false if 'n'.
bool prompt_user_for_yes_no(const string &message);

// Requires: Nothing
// Modifies: Nothing
// Effects: coordinates functions to calculate depth of field, magnification, and horizontal field of view for a photograph
void user_photograph();

int main() {
    user_photograph();
    return 0;
}

/***************** Global function definitions *****************/

double prompt_user_for_positive_double(const string &message, const string &error_message) {
    cout << message << endl;
    double user_input;
    while (!(cin >> user_input) || user_input <= 0) {
        cout << error_message << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cin.ignore();
    return user_input;
}

string prompt_user_for_string(const string &message, const string &error_message) {
    cout << message << endl;
    string user_input;
    getline(cin, user_input);
    while (user_input.empty()) {
        cout << error_message << endl;
        getline(cin, user_input);
    }
    return user_input;
}

void user_photograph() {
    string positive_double_error_message = "Please enter a positive number: ";
    double focal_length, f_stop, circle_of_confusion, frame_width, frame_height, subject_distance;
    opt_string name = nullopt;

    cout << "Welcome to Austin and Luke's Photograph Property Calculator! Please enter the requested information below." << endl;
    // get user input for all lens params
    cout << "Let's get the properties of your lens first:" << endl;
    focal_length = prompt_user_for_positive_double("Please enter the focal length of your lens (mm): ",
                                                          positive_double_error_message);
    f_stop = prompt_user_for_positive_double("Please enter the f/stop of your lens: ", positive_double_error_message);
    // get user input for camera params
    cout << "Now let's get the properties of your camera body:" << endl;
    circle_of_confusion = prompt_user_for_positive_double("Please enter your camera's circle of confusion (mm). "
                                                                 "Enter '0.02' if you are unsure, this is the traditional "
                                                                 "standard for APS-C sensors and 35mm film: ",
                                                                 positive_double_error_message);
    frame_width = prompt_user_for_positive_double("Please enter the width of your camera sensor (mm). "
                                                  "Enter '36' if you are unsure, this is the standard width of 35mm film"
                                                  "and most full frame digital sensors.", positive_double_error_message);
    frame_height = prompt_user_for_positive_double("Please enter the height of your camera sensor (mm). "
                                                  "Enter '24' if you are unsure, this is the standard height of 35mm film"
                                                  "and most full frame digital sensors.", positive_double_error_message);
    // get user input for photograph params
    // get subject distance
    cout << "Lastly, let's get some properties of your photograph:" << endl;
    subject_distance = prompt_user_for_positive_double("Please enter the distance your subject is from the lens (meters): ",
                                                       positive_double_error_message);
    // validate subject distance (m) is strictly larger than lens focal length (mm)
    while (subject_distance*MM_PER_METER <= focal_length) {
        subject_distance = prompt_user_for_positive_double("Your subject must be further away from the lens than the length of the lens: ",
                                                           positive_double_error_message);
    }

    // create objects
    Rectilinear_Lens lens = Rectilinear_Lens(focal_length, f_stop, name);
    Camera camera = Camera(circle_of_confusion, frame_width, frame_height, lens);
    Photograph photograph = Photograph(camera, subject_distance);

    // print photograph properties
    cout << "\n\nYour Photograph has the following Properties:" << endl;
    cout << photograph << endl;


}