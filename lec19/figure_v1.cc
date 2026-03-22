#include "figure_v1.hh"
#include "circle_v1.hh"
#include "rectangle_v1.hh"

#include <vector>

Figure::Figure() : Figure {"black", 0, 0} {} // ctor delegation
Figure::Figure(string colour, int x, int y) : colour{colour}, x{x}, y{y} {} // General ctor

Figure::~Figure() {} // Dtor does nothing interesting, but ...

void Figure::setPos(int x, int y) {
    this->x = x;
    this->y = y;
}
void Figure::getPos(int &x, int &y) const {
    x = this->x;
    y = this->y;
}

void Figure::setColour (string colour) {
    this->colour = colour;
}

string Figure::getColour() const {
    return colour;
}

int main (int argc, char* argv[]) {
    // Figure f; // Illegal

    Circle *c1 = new Circle {"cyan", 0, 0, 5};
    Rectangle r1 {"red", 5, 10, 2, 3};
    Circle c2 {"green", 1, 1, 3};

    Figure* f = new Circle {"blue", 2, 5, 6}; // coin flip?
    // just remember ints are init to zero by default

    vector<Figure*> v{}; // Polymorphic container!
    v.push_back(c1);
    v.push_back(&r1); // Legal, but don't do this!
    v.push_back(&c2); // ditto
    v.push_back(f);

    for (size_t i=0; i<v.size(); i++) { // Old way to iterate a vector
        Figure* fp = v.at(i);
        fp->draw(); // Polymorphism
    }

    for (const auto & fp : v){ // Modern sigma range-based for loop
        fp->draw();
    }
    delete c1;
    delete f;
}