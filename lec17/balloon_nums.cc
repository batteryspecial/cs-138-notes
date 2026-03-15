#include <string>
#include <iostream>
using namespace std;

class Balloon {
    public:
        Balloon();
        Balloon(string colour);

        virtual ~Balloon();
        static int getNumBalloons(); // static method decl
    private:
        const string colour;
        static int curNumBalloons; // static var decls
        static const string DefaultColour;
};

int Balloon::curNumBalloons = 0; // static var defs
const string Balloon::DefaultColour = "grey";

Balloon::Balloon() : colour { Balloon::DefaultColour } {
    Balloon::curNumBalloons++; // "Balloon::" helpful but not required
}

Balloon::Balloon(string colour) : colour{colour} {
    curNumBalloons++;
}
Balloon::~Balloon () {
    curNumBalloons--;
}

// Static method definition
int Balloon::getNumBalloons () {
    return curNumBalloons;
}

int main (int argc, char* argv[]) {
    Balloon rb {"red"};
    Balloon rbc1 = rb;
    // We usually call a static method using the class name,
    // tho we can also go thru an instance: rb.getNumBalloons()
    cout << "Num balloons = " << Balloon::getNumBalloons() << endl;
}