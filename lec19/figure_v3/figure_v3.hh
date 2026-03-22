#include <string>
#include <vector>
#include <iostream>

using std::string, std::vector, std::cout, std::endl;

class Figure {
public:
    virtual ~Figure();
    void draw() const;
    void setPosition(int x, int y);
    void getPosition(int &x, int &y) const;

protected:
    Figure(string kind, string colour, int x, int y);

private:
    const string kind; // By convention, we usually list const data members first
    string colour;
    int x, y;
};

class Circle : public Figure {
public:
    Circle (string colour, int x, int y, int radius);
    ~Circle();

    // other stuff
private:
    int radius;
};

class Rectangle : public Figure {
public:
    Rectangle (string color, int x, int y, int w, int h);
    ~Rectangle();

    // other stuff
private:
    int w, h;
};
