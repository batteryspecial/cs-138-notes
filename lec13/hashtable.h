#include <string>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

// EMPTY == never used; ACTIVE == in use; ZOMBIE == deleted
enum Status {EMPTY, ACTIVE, ZOMBIE};
const int NOT_FOUND = -1;

struct Node {
    int snum; // Student number, the "key" value
    string name; // "other stuff"
    Status status;
};
typedef vector<Node> HashTable;

// numActiveElements should be part of the table variable, not a standalone global variable
int numActiveElements;

// All table entries allocated at once
void HT_init (HashTable& table, int K) {
    table.resize(K);
    numActiveElements = 0;
    for (size_t i=0; i<K; i++) {
        table[i].status = EMPTY;
    }
}

// While this is a legal hash function, its "spread" is likely to be pretty awful
// We assume key >= 0 and numBuckets > 0
int myhash (int key, int numBuckets) {
    return key % numBuckets; // "%" is the "mod" function
}

void HT_insert(HashTable& table, string name, int snum) {
    cerr << "Insert: " << name << " " << snum << endl;
    const int numBuckets = table.size();

    // Real world: If full (or approaching full), we'd create
    // a new, larger vector and re-insert the existing
    // non-zombie elements one-by-one into the new vector
    assert(numActiveElements < numBuckets);

    int slot = myhash(snum, numBuckets);
    // Stop if you find a zombie slot or a never-used slot
    while (ZOMBIE != table[slot].status && EMPTY != table[slot].status) {
        // Or "while (ACT   IVE == table[slot].status)"
        slot = (slot + 1) % numBuckets;
    }
    // We're guaranteed that we'll find a valid slot eventually,
    // since we already checked numActiveElements < numBuckets
    table[slot].snum = snum;
    table[slot].name = name;
    table[slot].status = ACTIVE;
    numActiveElements++;
}

// Return NOT_FOUND (i.e., -1) if not found
int HT_lookupIndex (const HashTable & table, int snum) {
    cerr << "Looking up index: " << snum << endl;
    const int numBuckets = table.size();
    int slot = myhash (snum, numBuckets);
    for (size_t i = 0; i<numBuckets; i++) {
        if (EMPTY == table[slot].status) {
            // If we find an EMPTY slot, the key's not there
            return NOT_FOUND;
        } 
        else if (ACTIVE == table[slot].status && snum == table[slot].snum) {
            return slot; // Found it!
        }
        // else it's a ZOMBIE or (ACTIVE and not a match),
        // so keep going
        slot = (slot + 1) % numBuckets;
    }
    // We made it around the horn but didn't find the element
    return NOT_FOUND; // == -1
}

bool HT_has(const HashTable& table, int snum) {
    return NOT_FOUND != HT_lookupIndex(table, snum);
}

string HT_lookup(const HashTable& table, int snum) {
    cerr << "Lookup: " << snum << endl;
    const int index = HT_lookupIndex (table, snum);
    if (index == NOT_FOUND) {
        return ""; // lame, should really do something else
    } 
    else {
        return table[index].name; // return "other stuff"
    }
}

// Simple! HT_lookupIndex does the real work here!
void HT_remove (HashTable & table, int snum) {
    cerr << "Remove: " << snum << endl;
    const int index = HT_lookupIndex (table, snum);
    assert (NOT_FOUND != index && ACTIVE == table[index].status);
    table[index].status = ZOMBIE;
    numActiveElements--;
}

// All of the elements will be printed exactly once, but there is no particular ordering
void HT_print (const HashTable & table) {
    cout << "Printing table" << endl;
    for (size_t i=0; i<table.size(); i++) {
        if (ACTIVE == table[i].status) {
        cout << " " << i << " "
        << table[i].snum << " " // key
        << table[i].name << endl; // "other stuff"
    }
    }
}
