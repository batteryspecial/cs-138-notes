#include <iostream> // Filename: greep.cc; example from Brad Lushman
#include <string>
#include <sstream>
using namespace std;

// Print only lines that contain the token passed to argv[1]
// A bit like grep but will match only whole tokens
// Use cin to get match file
int main(int argc, char* argv[]) {
    if (argc == 1) {
        cerr << "Usage: greep <word>" << endl;
        return 1;
    }

    const string secretWord = argv[1];
    string line;
    while (getline(cin, line)) {
        // Check for the word in the line
        istringstream s {line};
        string token;

        while (s >> token) {
            if (token == secretWord) {
                cout << line << endl;
                break; // Don't print the line again
            }
        }
    }
}