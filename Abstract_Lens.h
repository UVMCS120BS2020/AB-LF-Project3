//
// Created by Luke on 2/12/2020.
//

#ifndef LF_PROJECT2_ABSTRACT_LENS_H
#define LF_PROJECT2_ABSTRACT_LENS_H

using namespace std;

// ToDo - What exactly should the lens class extend/inherit? The Lens class itself can serve as the abstract class.
class Abstract_Lens {
protected:
    enum lens_type {
        rectilinear,
        curvilinear
    };

    lens_type type;

public:


};


#endif //LF_PROJECT2_ABSTRACT_LENS_H
