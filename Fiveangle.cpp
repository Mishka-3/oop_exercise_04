#include "Figure.h"
#include "Fiveangle.h"
#include "Point.h"
#include "cmath"
#include <iostream>

/*double Fiveangle::get_Area() {
    double Ox1 = B.get_X() - A.get_X();
    double Oy1 = B.get_Y() - A.get_Y();
    double Ox2 = C.get_X() - A.get_X();
    double Oy2 = C.get_Y() - A.get_Y();
    double Area = 0.5 * (Ox1 * Oy2 - Oy1 * Ox2);
    return std::abs(Area);
}*/

double Fiveangle::get_Area() {
    double Area;
    Area = 0.5 * (A.get_X()*B.get_Y() + B.get_X()*C.get_Y() + C.get_X()*D.get_Y() + D.get_X()*E.get_Y() + E.get_X()*A.get_Y()
                - B.get_X()*A.get_Y() - C.get_X()*B.get_Y() - D.get_X()*C.get_Y() - E.get_X()*D.get_Y() - A.get_X()*E.get_Y());
    return std::abs(Area);
}

Point Fiveangle::get_center() {
    double x, y;
    x = (A.get_X() + B.get_X() + C.get_X() + D.get_X() + E.get_X()) / 5.0;
    y = (A.get_Y() + B.get_Y() + C.get_Y() + D.get_X() + E.get_X()) / 5.0;
    Point center(x, y);
    return center;
}

Fiveangle::Fiveangle() : A(Point()), B(Point()), C(Point()), D(Point()), E(Point()) {
}

Fiveangle::Fiveangle(Point a, Point b, Point c, Point d, Point e) : A(a), B(b), C(c), D(d), E(e) {
}

Fiveangle::Fiveangle(std::istream& in) {
    in >> A >> B >> C >> D >> E;
}

size_t Fiveangle::get_Vertex() {
    return (size_t)(5);
}

std::ostream& operator<<(std::ostream& out, Fiveangle& S) {
    out << S.A << ' ' << S.B << ' ' << S.C << ' ' << S.D << ' ' << S.E << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Fiveangle& S) {
    in >> S.A >> S.B >> S.C >> S.D >> S.E;
    return in;
}

bool Fiveangle::operator==(const Fiveangle& S) {
    return ((A == S.A) && (B == S.B) && (C == S.C) && (D == S.D) && (E == S.E));
}

Fiveangle& Fiveangle::operator=(const Fiveangle& S) {
    if (this == &S) {
        return *this;
    }
    A = S.A;
    B = S.B;
    C = S.C;
    D = S.D;
    E = S.E;
    return *this;
}
