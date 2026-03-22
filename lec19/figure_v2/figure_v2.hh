#include <string>
#include <vector>
#include <iostream>

using std::string, std::vector, std::cout, std::endl;

class Figure {
    public:
        virtual ~Figure();
        void draw() const; // No longer virtual!
        void setPos(int x, int y);
        void getPos(int &x, int &y) const; // No longer ambiguous, we will be using reference params
    
    protected:
        Figure(string colour, int x, int y);
    
    private:
        virtual string getKind() const = 0;
        string colour;
        int x, y;
};

// No longer pure virtual (or even virtual!)
void Figure::draw() const {
    cout << getKind() << " " << colour << " " << x << " " << y << endl;
}

class Circle : public Figure {
    public:
        Circle(string colour, int x, int y, int radius);
        virtual ~Circle();

        // area(), get/setRadius, PI, etc.
    private:
        virtual string getKind() const override;
        int radius;
};

string Circle::getKind() const {
    return "Circle";
}

class Rectangle : public Figure {
    public:
        Rectangle(string colour, int x, int y, int w, int h);
        virtual ~Rectangle();

        // area(), get/setSize, etc.
    private:
        virtual string getKind() const override;
        int w, h;
};

string Rectangle::getKind() const {
    return "Rectangle";
}
