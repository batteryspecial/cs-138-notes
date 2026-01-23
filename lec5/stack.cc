#include <iostream>
#include "stack.h"

using namespace std;

int main (int argc, char* argv[]) {
    Stack s = initStack();

    s = push (s, "alice");
    s = push (s, "bob");
    s = push (s, "carol");

    cout << peek(s) << endl;
    s = pop(s);

    // However you don't get copy semantics
    // s1 = s2 will result in a memory leak (s2 memory not deleted)

    cout << peek(s) << endl;
    s = nuke(s);

    return 0;
}

