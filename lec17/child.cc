#include <string>
#include <iostream>
using namespace std;

class Balloon {
    public:
        Balloon(string colour = "grey");
        virtual ~Balloon();
        void speak () const;
    private:
        const string colour;
};
Balloon::Balloon(string colour) : colour(colour) {}
Balloon::~Balloon() {}
void Balloon::speak() const {
    cout << colour << " balloon" << endl;
}

class Child {
    public:
        Child();
        Child(string name);
        Child(string name, string balloon_color);
        virtual ~Child();
        
        void speak() const;
    private:
        const string name;
        Balloon *balloon; // now we have balloon as a private field
};

Child::Child() : name("big jah"), balloon(nullptr) {}
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
