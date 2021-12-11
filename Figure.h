#ifndef OOP_EXERCISE_03_FIGURE_H
#define OOP_EXERCISE_03_FIGURE_H

#include "Point.h"

class Figure {
public:
    virtual size_t get_Vertex() = 0;
    virtual double get_Area() = 0;
    virtual Point get_center() = 0;
    ~Figure() {
    }
};
#endif //OOP_EXERCISE_03_FIGURE_H