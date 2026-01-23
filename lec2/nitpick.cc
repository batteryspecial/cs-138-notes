#include <iostream>
#include <string>
using namespace std;

// But it's actually a little more complicated ...
int main (int argc, char* argv[]) {
    int n; // read in an int
    cin >> n;
    if (cin.fail()) { // Line **
        cout << "Oops, couldn't read the int." << endl;
        return 1;
    }
    cout << "n = " << n << endl;

    string flurble; // read in a string
    cin >> flurble;
    if (cin.fail()) {
        cout << "Oops, couldn't read the string." << endl;
        return 1;
    }
    cout << "flurble = \"" << flurble << "\"" << endl;
}