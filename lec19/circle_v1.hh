#include "figure_v1.hh"

Circle::Circle() : Figure{}, radius{0} {}
Circle::Circle(string colour, int x, int y, int radius) : Figure{colour, x, y}, radius{radius} {} // using the explict parent ctor
Circle::~Circle() {}

const double Circle::PI = 3.14; // For more discussion **

double Circle::area() const {
    return radius * radius * PI;
}

void Circle::draw() const {
    cout << "Circle " << colour << " " << x << " " << y << endl;
}

void Circle::setRadius(int radius) {
    this->radius = radius;
}
int Circle::getRadius() const {
    return this->radius;
}
