#ifndef OOP_EXERCISE_03_TRIANGLE_H
#define OOP_EXERCISE_03_TRIANGLE_H

#include "Point.h"
#include "Figure.h"

class Fiveangle : Figure {
private:
    Point A, B, C, D, E;
public:
    Fiveangle(std::istream& in);
    size_t get_Vertex();
    double get_Area();
    Fiveangle();
    Fiveangle(Point a, Point b, Point c, Point d, Point e);
    Point get_center();
    friend std::istream& operator>> (std::istream& in, Fiveangle& S);
    friend std::ostream& operator<< (std::ostream& out, Fiveangle& S);
    Fiveangle& operator= (const Fiveangle& S);
    bool operator== (const Fiveangle& S);
};
#endif //OOP_EXERCISE_03_TRIANGLE_H