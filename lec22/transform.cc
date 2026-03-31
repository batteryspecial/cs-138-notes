#include <iostream> // We saw this before ...
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main (int argc, char* argv[]) {
    // Count the number of times each word appears in a token stream
    map<string, int> m {}; // Could use a multiset instead
    string token;
    while (cin >> token) { // This is where it all happens
        // transform to lower case, using STL algorithm transform
        transform(token.begin(),token.end(),token.begin(),::tolower);
        m[token]++;
    }

    // After below line is executed, m["the"] is added to the
    // map even if it didn't appear in the input stream
    cout << "\"the\" occurred " << m["the"] << " times\n";

    // So let’s erase it if so ... could erase other stop words too
    if (0 == m["the"]) {
        m.erase("the");
    }

    // Or do it this way that doesn't mutate m just by asking
    if (m.count("the") > 0) { // 1 == found, 0 == not found
        cout << "\"the\" occurred " << m["the"] << " times\n";
    }

    // map supports bi-directional iterators; this will print pairs in
    // "alphabetic" order of keys; i's type here is std::pair<string, int>&
    // (pair is defined in <utility>)
    const int interestingnessThreshold = 5;
    for (const auto & i : m) {
        // For maps, "first" gets you the key ...
        // ... and "second" gets you the value
        if (i.second >= interestingnessThreshold)
            cout << i.second << " " << i.first << endl;
    }
}
