#include <iostream>
#include <cassert>
#include <vector>
#include <string>

using namespace std;

// Open hashing with chaining
struct Node { // Node is as before
    int snum; // key value
    string name; // "other stuff"
    Node* next;
};

class HashTable {
public :
    HashTable();
    HashTable(int K);
    virtual ~HashTable();

    void insert(string name, int snum);
    bool lookup(int snum) const;
    void remove(int snum);
    void print() const; // for debugging

    static const int DefaultSize;

private:
    vector<Node*> table;
    int hash(int key) const;
};

// A static const is like a global const, but it's tied to the class, meaning one-per-universe, not one-per-class
const int HashTable::DefaultSize = 1000;

// these are C++ initializers, more on this later
HashTable::HashTable() : table(DefaultSize) {}
HashTable::HashTable(int K) : table(K) {}

// look at this
HashTable::~HashTable(){
    for (size_t i=0; i < table.size(); i++) {
        // for each node of the table
        Node* p = table.at(i);

        // nuke the associated chain
        while (nullptr != p) {
            Node* temp = p;
            p = p->next;
            delete temp;
        }
    }
}

// We covered this, a very poor hash function, but it works
// This method cannot be static, because it needs to be unique-per-class, different keys -> different hashes
int HashTable::hash(int key) const {
    return key % (int)table.size();
}

// We basically assume we have the linked structure at that key
// which is totally reasonable because we have the vector
bool HashTable::lookup(int key) const {
    const int slot = hash(key);
    Node* temp = table.at(slot);
    
    while (nullptr != temp) {
        if (temp->snum == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void HashTable::insert(string name, int snum) {
    const int slot = hash(snum);
    Node* newNode = new Node {
        .snum = snum,
        .name = name,
    }; // Overflow list is unordered

    newNode->next = table.at(slot);
    table.at(slot) = newNode; // we have 1000 slots, we should be safe
}

void HashTable::remove(int snum) {
    const int slot = hash(snum);

    Node **pres = &table.at(slot);
    // for safety, if the hash doesn't even exist, we have nothing to remove
    if (!pres) return;

    // why we are using a double pointer? with single pointers we need a *prev and a *curr
    // with a single pointer we only change the copy of the address
    // with double pointers we literally change the address

    while (*pres) {
        if ((*pres)->snum == snum) {
            Node *del = *pres;
            // like in this example, the current pointer's memory address becomes the memory address of the next element
            *pres = (*pres)->next;
            // while the element at the old memory address is deleted
            delete del;

            // you might ask, what about prev of that block we deleted, the thing is prev -> [memory address of next block]
            // using double pointers, we quite literally changed that memory address, avoiding the need for a *prev pointer

            // in the case of one element, that memory address probably holds a nullptr, which now is also the mem address of that table Node*
            // as we can see, using double pointers is a very elegant technique in this special deletion case
            return;
        }

        // we are saying, the double pointer now points to the memory address of the pointer to the next element
        pres = &((*pres)->next);
    }
}

// This just prints the bucket lists in numerical bucket
// order; it does not print the table as sorted, of course.
void HashTable::print() const {
    for (size_t i=0; i < table.size(); i++) {
        Node* p = table.at(i);
        while (p) {
            cout << i << " " << p->snum << " " << p->name << endl;
            p = p->next;
        }
    }
}

