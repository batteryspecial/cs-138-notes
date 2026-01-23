// Try running this with different #s of command-line args
#include <iostream>
#include <string>
using namespace std;

int main (int argc, char* argv[]) {
    

    cout << "argc = " << argc << endl;
    for (size_t i=0; i<argc; i++) {
        cout << "argv[" << i << "] = \"" << argv[i] << "\"" << endl;
    }
}