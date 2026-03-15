#include <string>
#include <cassert>
#include <iostream>
using namespace std;

class Balloon {
    public:
        Balloon(string colour = "grey");
        virtual ~Balloon();
        void speak() const;
    private:
        const string colour;
        static int numballoons;
};

// static instantiation
int Balloon::numballoons = 0;

Balloon::Balloon(string colour) : colour(colour) {
    Balloon::numballoons++;
}
Balloon::~Balloon() {
    Balloon::numballoons--;
}
void Balloon::speak() const {
    cout << colour << " balloon" << endl;
}

class Child {
    public:
        Child(string name);
        Child(string name, string color);
        virtual ~Child();
        void speak() const;
        void getBalloon(Balloon* balloon);
        Balloon *giveBalloon();
    private:
        string name;
        Balloon *balloon;
};
Child::Child(string name) : name(name), balloon(nullptr) {}
Child::Child(string name, string balloon_color) : name(name), balloon(new Balloon{balloon_color}) {}

Child::~Child() {
    if (nullptr != balloon) {
        delete balloon;
    }
}
void Child::speak () const {
    cout << name;
    // Need to special kid case with no balloon
    if (nullptr != balloon) {
        cout << " with a ";
        balloon->speak(); // endl provided by Balloon::speak
    } 
    else {
        cout << endl;
    }
}

void Child::getBalloon(Balloon *incoming) {
    if (this->balloon != nullptr) {
        delete this->balloon;
    }
    this->balloon = incoming;
}

Balloon *Child::giveBalloon() {
    // should we assert this->balloon != nullptr?
    // may cause excessive complications

    Balloon *transfer = this->balloon;
    this->balloon = nullptr;

    return transfer;
}
