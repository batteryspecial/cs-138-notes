#include <iostream>
#include <string>
#include "Child.h"
#include "Balloon.h"
using namespace std;

Child::Child(string name, string bColour) : name(name), pb(new Balloon{bColour}) {}
Child::~Child() {
    delete pb;
}

void Child::speak() const {
    cout << "Child named " << name << " with a ";
    pb->speak();
}