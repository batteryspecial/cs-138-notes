#include <iostream>
#include <string> // <> -> library
#include "Balloon.h" // "" ->local file

// OK in .cc files
using namespace std;

Balloon::Balloon (string colour) : colour(colour) {}

void Balloon::speak() const {
    cout << colour << " balloon" << endl;
}