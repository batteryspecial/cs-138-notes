#include <vector>
#include <iostream>
using namespace std;

int main (int argc, char* argv[]) {
    vector<int> v {4, 5}; // {4, 5}

    // Note: vector<int> v (4, 5); produces {5, 5, 5, 5}
    v.push_back(6); // {4, 5, 6}
    v.push_back(7); // {4, 5, 6, 7}

    // Loop thru (we've seen this before)
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    } // Output: 4 5 6 7
    
    // similar to above, but less typing (we've also seen this before)
    for (const auto & n : v) {
        cout << n << endl;
    } // Output: 4 5 6 7

    // Go in reverse order; note that ++ goes backwards (reverse) too.
    // Use iterators returned by methods v.rbegin() and v.rend()
    for (vector<int>::reverse_iterator it = v.rbegin();
        it != v.rend(); ++it) {
        cout << *it << endl;
    } // Output: 7 6 5 4

    // Same, but less typing
    // rbegin() has return type vector<int::reverse_iterator
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it << endl;
    } // Output: 7 6 5 4

    // const iterator: I promise no changes to the elements
    // Use iterators returned by methods v.cbegin(), v.cend()
    for (auto it = v.cbegin(); it!= v.cend(); ++it) {
        cout << *it << endl;
    } // Output: 4 5 6 7

    // A different way of promising not to change the elements
    for (const auto & i : v) { // each i will be an int, not an int*
        cout << i << endl; // i is not a ptr, no need to deref
    } // Output: 4 5 6 7
}