#include "figure_v1.hh"

Rectangle::Rectangle() : Figure{}, w{0}, h{0} {}
Rectangle::Rectangle(string colour, int x, int y, int w, int h) : Figure{colour, x, y}, w{w}, h{h} {}

Rectangle::~Rectangle() {}

double Rectangle::area() const {
    return w * h;
}
void Rectangle::draw() const {
    cout << "Rectangle " << colour << " " << x << " " << y << endl;
}

void Rectangle::setSize (int w, int h){
    this->w = w;
    this->h = h;
}
// different from returning an int, what we had earlier - design inconsistency
void Rectangle::getSize (int &w, int &h) const {
    w = this->w;
    h = this->h;
}