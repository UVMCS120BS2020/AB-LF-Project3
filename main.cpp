#include <iostream>
#include <iomanip>
#include <memory>
#include "Lens.h"
#include "globals.h"
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

typedef optional<string> opt_string;


// the conversion factor between mm and meters
double const MM_PER_METER = 1000;

/******************** Global function prototypes ***********************/

// Requires: Nothing
// Modifies: cin, cout
// Effects: Prompts user for non-neg double input using custom message, returns validated input
double prompt_user_for_positive_double(string &message, string &error_message);

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
// Effects: coordinates functions to calculate depth of field, magnification, and horizontal field of view for a lens
void user_lens_calculator();

int main() {
    user_lens_calculator();
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

bool prompt_user_for_yes_no(const string &message) {
    cout << message << "\nPlease enter 'y' for yes, or 'n' for no: " << endl;
    string user_input;
    cin >> user_input;
    while (user_input != "y" && user_input != "n") {
        cout << "Please enter 'y' for yes, or 'n' for no: " << endl;
        cin.clear();
        cin.ignore();
        cin >> user_input;
    }
    cin.ignore();
    return (user_input == "y");
}

void user_lens_calculator() {
    string positive_double_error_message = "Please enter a positive number: ";
    double focal_length, f_stop, circle_of_confusion, frame_width, frame_height, subject_distance;
    opt_string name = nullopt;

    cout << "Welcome to Luke's Lens calculator! Please fill out the following information to create your lens." << endl;
    // get user input for all lens params
    focal_length = prompt_user_for_positive_double("Please enter the focal length of your lens (mm): ",
                                                          positive_double_error_message);
    f_stop = prompt_user_for_positive_double("Please enter the f/stop of your lens: ", positive_double_error_message);
    circle_of_confusion = prompt_user_for_positive_double("Please enter your desired circle of confusion (mm). "
                                                                 "Enter '0.02' if you are unsure, this is the traditional "
                                                                 "standard for APS-C sensors and 35mm film: ",
                                                                 positive_double_error_message);
    frame_width = prompt_user_for_positive_double("Please enter the width of your sensor (mm). "
                                                  "Enter '36' if you are unsure, this is the standard width of 35mm film"
                                                  "and most full frame digital sensors.", positive_double_error_message);
    frame_height = prompt_user_for_positive_double("Please enter the height of your sensor (mm). "
                                                  "Enter '24' if you are unsure, this is the standard height of 35mm film"
                                                  "and most full frame digital sensors.", positive_double_error_message);

    // get lens name if wanted
    bool using_name = prompt_user_for_yes_no("Would you like to name your lens?");
    if (using_name) {
        name = prompt_user_for_string("Please enter the name of your lens: ", "Please enter a name: ");
    }

    unique_ptr<Lens> lens = make_unique<Lens>(focal_length, f_stop, circle_of_confusion, frame_width, frame_height, name);

    // get subject distance
    subject_distance = prompt_user_for_positive_double("Please enter the distance your subject is from the lens (meters): ",
                                                       positive_double_error_message);
    // validate subject distance (m) is strictly larger than lens focal length (mm)
    while (subject_distance*MM_PER_METER <= lens->get_focal_length()) {
        subject_distance = prompt_user_for_positive_double("Your subject must be further away from the lens than the length of the lens: ",
                                                           positive_double_error_message);
    }

    double depth_of_field = lens->depth_of_field(subject_distance);
    double magnification = calculate_magnification(*lens, subject_distance);
    double fov_horizontal = field_of_view_horizontal(*lens, magnification);

    if (lens->get_name() != nullopt) {
        cout << "\nFor lens '" << *lens->get_name() << "': " << endl;
    }
    cout << *lens << endl;

    cout << "DOF =\t\t";
    if (depth_of_field >= 0) {
        cout << setprecision(3) << depth_of_field << " meters" << endl;
    } else {
        cout << "infinite, subject is beyond hyper-focal distance" << endl;
    }
    cout << "Magnification =\t" << setprecision(3) << magnification << " x" << endl;
    cout << "Hor. FOV =\t" << setprecision(3) << fov_horizontal << " degrees" << endl;
}