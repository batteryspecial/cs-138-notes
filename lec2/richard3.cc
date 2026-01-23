#include <iostream>
#include <string>
using namespace std;

// This prints all of the input stream, one "token" at a time
// surrounded by double quotes, but none of the whitespace in
// the input is preserved
int main (int argc, char* argv[]) {
    string token;
    // Using getline prints all of the input stream, one line at a time, including
    // all whitespace in the input; each line is surrounded by quotes so
    // you can see that leading/trailing whitespace is preserved
    while (cin >> token) { //getline(cin, token) 
        cout << "\"" << token << "\"" << endl;
    }
}

// . is a space
// <NL> is newline
// <EOF> is the end of the line
