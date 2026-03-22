// Design #1: It works, but could be cleaner
#include <string>
#include <iostream>
using namespace std;

class Figure {
    public:
        virtual ~Figure();
        virtual double area() const = 0; // Pure virtual" methods are abstract in parent, and defined later by children
        virtual void draw() const = 0;
        void setPos(int x, int y);
        void getPos(int &x, int &y) const;
        void setColour(string colour);
        string getColour() const;
    protected :
        Figure(); // Huh? ctors are protected??
        Figure(string colour, int x, int y); // WT??
        string colour;
        int x, y;
};

class Circle : public Figure {
    public:
        Circle();
        Circle(string color, int x, int y, int radius);

        virtual ~Circle(); // who knows we might have cylinders
        virtual void draw() const override;
        virtual double area() const override;

        // NEW
        int getRadius() const; 
        void setRadius(int radius);
        static const double PI;

    private:
        // NEW
        int radius;
};

class Rectangle : public Figure {
    public:
        Rectangle();
        Rectangle(string color, int x, int y, int w, int h);

        virtual ~Rectangle();
        virtual void draw() const override;
        virtual double area() const override;

        void setSize(int w, int h); // new
        void getSize(int &w, int &h) const; // ??? not the same as circle!
    
    private:
        int w;
        int h;
};
