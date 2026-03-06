#include <iostream>
#include <string>
using namespace std;

struct sBalloon { 
    // old way of doing things
    string colour;
};

void speak(const sBalloon & b) {
    cout << "I'm a " << b.colour << " balloon" << endl;
}

int main(int argc, char* argv[]) {
    sBalloon b1 {}; // On stack
    b1.colour = "red";
    sBalloon b2 {}; // On stack
    b2.colour = "red";
    sBalloon* pb3 = new sBalloon {}; // On heap
    pb3->colour = "green";
    speak(b1);
    speak(*pb3);
    delete pb3;
}