#include <iostream>
#include <string>
#include "Balloon.h" // This include isn't strictly needed
#include "Child.h"

using namespace std;

int main(int argc, char* argv[]) {
    Child ian {"Ian", "red"};
    Child trev {"Trevor", "green"};
    Child *alex = new Child{"Alex", "yellow"};

    trev.speak();
    ian.speak();
    alex->speak();
}