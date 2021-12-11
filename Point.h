#ifndef OOP_EXERCISE_03_POINT_H
#define OOP_EXERCISE_03_POINT_H

#include <iostream>

class Point {
private:
    double x;
    double y;
public:
    Point();
    double get_X();
    double get_Y();
    double get_distance(Point& point2);
    friend std::ostream& operator<< (std::ostream& out, Point& point);
    friend std::istream& operator>> (std::istream& in, Point& point);
    bool operator == (const Point& Point2);
    Point operator = (const Point& Point2);
    Point(double d, double d1);
};
#endif //OOP_EXERCISE_03_POINT_H