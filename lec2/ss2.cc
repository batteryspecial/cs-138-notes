#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Echo all integers; skip non-integers
int main (int argc, char* argv[]) {
    string s;
    while (cin >> s) {
        // Create an input string stream out of s
        istringstream iss{s};

        int n;
        if (iss >> n) {
            // Successfully extracted integer from iss!
            cout << n << endl;
        }
    }
}
