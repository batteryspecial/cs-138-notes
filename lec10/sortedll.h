#include <string>
#include <cassert>
#include <iostream>

using namespace std;

struct Node {
    string val;
    string other;
    Node* next;
};

typedef Node* SortedList;

/**
 * @pre first **cannot** be a non-empty list.
 * @post Creates an empty sorted linked list.
 */
void initList(SortedList& first) {
    first = nullptr;
}

bool isEmpty (const SortedList& first) {
    return nullptr == first;
}

/**
 * @returns True if *val* exists, false it it doesn't.
 */
bool has(const SortedList& first, string val) {
    Node* c = first;
    while(c && c->val < val) {
        c = c->next;
    }

    if (nullptr == c || c->val != val) {
        return false;
    } else {
        return true;
    }
}

void insert (SortedList & first, string val) {
    // cerr << "Inserting " << val << endl; // debug
    Node* newNode = new Node {};
    newNode->val = val;
    if (isEmpty(first) || val <= first->val) {
        // Cases 1-2: insert *as* first element
        newNode->next = first;
        first = newNode;
    } else {
        // Cases 3-6: insert *after* first element
        Node* cur = first;
        while (cur->next && val > cur->next->val){
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

// Final version, that combines all cases into
// two main scenarios; requires list be sorted already.
void remove (SortedList& first, string val) {
    // cerr << "Deleting \"" << val << "\"\n"; // debug
    // Case 1: List MT, abort
    assert (!isEmpty(first));
    Node* temp; // temp is declared outside of the if/loop
    if (first->val == val) {
        // Case 2: Non-MT list, delete first element
        temp = first;
        first = first->next;
    } else {
        // Case 3-5: Non-MT list, delete non-first element
        Node* cur = first;
        while (nullptr != cur->next && val > cur->next->val) {
            cur = cur->next;
        }
        // My orig (wrong) 2009 version: if (nullptr == cur ...)
        if (nullptr == cur->next || val != cur->next->val) {
            // Case 5: Non-MT list, element not present
            // assert (false); // or better: just return
            cerr << "Couldn't find \"" << val << "\"\n";
            return;
        }
        // Case 3-4: Non-MT list, element present
        temp = cur->next;
        cur->next = cur->next->next; // aka temp->next
    }
    // Common to both scenarios; this is why temp was
    // declared outside of the if/loop
    delete temp;
}
