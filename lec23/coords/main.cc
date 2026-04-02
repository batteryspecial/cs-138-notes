#include <iostream>
#include "Coords.h"
using namespace std;

// These are overloads of the global operators, and so don't belong in Coord.cc
Coord operator+(const Coord &c1, const Coord &c2) {
    return Coord{c1.x + c2.x, c1.y + c2.y};
}

Coord operator*(const int k, const Coord &c) {
    return Coord{k * c.x, k * c.y};
}

Coord operator*(const Coord &c, const int k) {
    return k * c;
}

ostream &operator<<(ostream &out, const Coord &c) {
    out << "(" << c.x << ", " << c.y << ")";
    return out;
}

istream &operator>>(istream &in, Coord &c) {
    in >> c.x >> c.y;
    return in;
}

int main (int argc, char* argv[]) {
    Coord c1 {3, 5}, c2 {};
    cin >> c2;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    const int k1 = 5;
    cout << c1 << " + " << c2 << " = " << c1+c2 << endl;
    cout << c1 << " * " << k1 << " = " << c1*k1 << endl;
    cout << k1 << " * " << c2 << " = " << c2*k1 << endl;
}
