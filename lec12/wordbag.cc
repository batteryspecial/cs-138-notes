// This creates a "word bag" for a text file.
#include <iostream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

// Return a copy of s with all non-letter chars removed,
// and all letters converted to lower case.
// Note that this will return an empty string if the
// original token has no alphabetic chars in it.
string trim(string s) {
    string ans = "";
    for (const auto & c : s) {
        if (isalpha(c)) {
            ans += tolower(c);
        }
    }
    return ans;
}

int main (int argc, char* argv[]) {
    // Track the number of times each (different) word
    // appears in stdin
    map<string, int> m {};
    string token;

    while (cin >> token) { // This is where the magic happens
        m[trim(token)]++;
    }

    // Here's a simple way to iterate through the elements
    // of a map (we'll revisit "iterators" later")
    for (const auto & x : m) {
        cout << x.first << " " << x.second << endl;
    }
    
    // We could have done anything to the map, like using other libraries to perform NLP
    // Afterwards we can do pairwise cosine similarity on all the documents to find those similar topics
}