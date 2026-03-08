#include <iostream>
#include <string>
using namespace std;

class Balloon { // Class declaration; often in a .h file
    public:
        Balloon();
        Balloon(string colour);
        virtual ~Balloon(); // this is a destructor
        void speak() const;
    private:
        string colour;
};

// Method definitions; often in a different file (.cc), but we'll use the .h file for now

Balloon::Balloon () { // default constructor (better way: use initializers)
    this->colour = "grey";
}
Balloon::Balloon (string colour) { // another constructor
    this->colour = colour;
}
Balloon::~Balloon() {} // deconstructor

// This member function promises not to modify the object’s non‑mutable data members
void Balloon::speak() const {
    cout << "I'm a " << this->colour << " balloon!" << endl;
}
