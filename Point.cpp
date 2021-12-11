#include "Point.h"
#include <cmath>

bool Point::operator==(const Point& Point2) {
    return((x == Point2.x) && (y == Point2.y));
}

Point Point::operator=(const Point& Point2) {
    x = Point2.x;
    y = Point2.y;
    return *this;
}

Point::Point() {}

double Point::get_X() {
    return x;
}

double Point::get_Y() {
    return y;
}

double Point::get_distance(Point& point2) {
    double distance, distance_x, distance_y;
    distance_x = x - point2.x;
    distance_y = y - point2.y;
    distance = distance_x * distance_x + distance_y * distance_y;
    return sqrt(distance);
}

std::ostream& operator<< (std::ostream& out, Point& point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}

std::istream& operator>> (std::istream& in, Point& point) {
    in >> point.x;
    in >> point.y;
    return in;
}

Point::Point(double d, double d1) {
    x = d;
    y = d1;
}