#include "evil.hh"
#include <iostream>

// Version 1 of default ctor
// EvilGenius::EvilGenius () {}

// Version 2 is functionally identical, but more explicit
EvilGenius::EvilGenius() : name(), pet() {}

EvilGenius::EvilGenius(string name, Monster pet) : name(name) {
    this->pet = pet;
}

EvilGenius::EvilGenius(string name, const Monster& pet) : name{name}, pet{pet} {
    cerr << "Creating an EvilGenius named " << name << " with pet " << pet.get_type() << endl;
}

EvilGenius::~EvilGenius() {}