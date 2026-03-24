#include <iostream>
using namespace std;

// Our old friend, same as before
class Balloon {
public:
    Balloon(string colour);
    virtual ~Balloon();
    void speak() const;
private:
    string colour;
};

Balloon::Balloon(string colour) : colour{colour} {}
Balloon::~Balloon(){
    cout << colour << " balloon pops" << endl;
}
void Balloon::speak() const {
    cout << colour << " balloon" << endl;
}

class Parent { // Models a human parent
public :
    Parent(string name); // But no dtor for now
    void speak() const; // Not virtual, but should be
private:
    string name;
};
Parent::Parent(string name) : name {name} {
    cout << name << " is born" << endl;
}

// If we don't define a dtor, we get the default one, which is public and non-virtual; this seems OK at the moment, since Parent has no heap-based sub-parts, but watch what happens
void Parent::speak() const {
    cout << "Hi, I'm " << name << endl;
}

class Child : public Parent { // Models a human child
public:
    Child(string name, string bColour);
    ~Child();
    void speak() const;
    void cleanRoom();
private:
    Balloon *b;
};

Child::Child(string name, string bColour) : Parent{name}, b{new Balloon{bColour}} {}
    Child::~Child(){ // Need a dtor as Balloon is on heap
    delete b;
}
void Child::speak() const { // Override speak, cos Balloon
    Parent::speak(); // You can call the Parent's method in the Child
    cout << " with a ";
    b->speak();
}

void Child::cleanRoom() {
    cout << "I'll do it later, geesh. <eyeroll>" << endl;
}
