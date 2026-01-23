/**
 * The interface for a stack that will be the same for any implementation in a linked list style.
 * First, we'll look at an implementation that uses a linked list, the abstract interface should be the same.
 * 
 * Again, for now we assume an element type of string.
 * Generic stacks (coming later) will take any kind of element, like a vector does.
 */

#include <string>
#include <cassert>
using namespace std;

struct Node {
    string val;
    Node *next;
};

// Hiding the details of the implementation
typedef Node* Stack;

Stack push(Node *first, string val) {
    Node *newnode = new Node {};
    newnode->val = val;
    newnode->next = first;
    
    return newnode;
}

Stack initStack() {
    return nullptr;
}

bool isEmpty(Stack first) {
    return (first == nullptr);
}

Stack pop(Stack first) {
    assert(!isEmpty(first));
    Stack newfirst = first->next;
    delete first;
    return newfirst;
}

string peek(Stack first) {
    assert(!isEmpty(first));
    return first->val;
}

/*
while (first != nullptr) {
        Stack temp = first;
        first = first->next;
        delete temp;
    }
    return nullptr; // first
*/
Stack nuke(Stack first) {
    // This is much cleaner
    while (!isEmpty(first)) {
        first = pop(first);
    }
    return nullptr;
}
