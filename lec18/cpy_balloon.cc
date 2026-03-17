#include <iostream>
#include <string>
using namespace std;

class Balloon {
public:
    Balloon(string colour);
    Balloon(const Balloon& other);
    string getColour() const;
private:
    string colour;
};

Balloon::Balloon(string colour) : colour {colour} {
    cerr << "normal ctor: " << colour << endl;
}

// copy ctor
Balloon::Balloon(const Balloon& other) : colour {other.colour} {
    cerr << "copy ctor: " << colour << endl;
}

Balloon& Balloon::operator=(const Balloon& b) {
    cerr << "assignment ctor: " << colour << endl;
}

string Balloon::getColour() const {
    return colour;
}

// Not part of Balloon interface
Balloon makeMeOne(Balloon b) {
    const string colour = b.getColour();
    Balloon newBalloon{colour};
    return newBalloon;
}
Balloon makeMeOneToo(const Balloon &b){
    const string colour = b.getColour();
    Balloon newBalloon{colour};
    return newBalloon;
}
// Some surprises in store ...
int main (int argc, char* argv[]) {
    Balloon rb {"red"};
    Balloon rb1 {rb};
    Balloon rb2 {rb.getColour()};
    Balloon rb3 {makeMeOne(rb)};
    Balloon rb4 {makeMeOneToo(rb)};
}