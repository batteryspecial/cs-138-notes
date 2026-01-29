#include <vector>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

// This design can become very inefficient over time,
// but it does "work"
struct Queue {
    vector<string> store {}; // Instantiating a queue causes
    // a vector to be instantiated
    int first; // first is the index "one beyond" the
}; // current oldest element

void initQueue (Queue & q) {
    q.first = 0; // No elements yet, so "one beyond" is
} // element zero

bool isEmpty (const Queue & q) {
    // NOT this: q.store.empty() ... but why?
    // it's because the vector doesn't really shrink, we are purely using an index
    return q.store.size() == q.first;
}

void enter (Queue & q, string val) {
    q.store.push_back(val);
}

void leave (Queue & q) {
    // Note that we do NOT call q.store.pop_back()
    // We just increment the index to the first element
    assert (!isEmpty(q));
    q.first++;
}

string first (const Queue & q) {
    assert (!isEmpty(q));
    return q.store.at(q.first);
}

// Nuke is a bit odd in this case
void nuke (Queue & q) {
    q.store.clear(); // similar to q.store.resize(0)
    initQueue (q); // clear may not reset capacity to 0, tho
}
