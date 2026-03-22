#include "figure_v3.hh"

Figure::Figure(string kind, string colour, int x, int y) : kind{kind}, colour{colour}, x{x}, y{y} {}

// we don't even need getKind() anymore
void Figure::draw() const {
    cout << colour << " " << kind << endl;
}

// base class fills in its own variables first! even if kind is private, it is filled in before any code in Circle executes
Circle::Circle(string colour, int x, int y, int radius) : Figure("Circle", colour, x, y), radius{radius} {}

Rectangle::Rectangle(string colour, int x, int y, int w, int h) : Figure("Rectangle", colour, x, y), w{w}, h{h} {}
