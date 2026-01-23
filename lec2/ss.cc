#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Check if input token was an integer; if not, try again
int main (int argc, char* argv[]) {
    int n;
    while (true) {
        cout << "Enter an integer: ";
        string s;
        cin >> s;

        // Create an input string stream out of s
        istringstream iss {s};
        if (iss >> n) {
            break; // Stop if the string contains a number
        }
        cout << "Ooops, try again" << endl;
    }
    cout << "You entered " << n << endl;
}