#include <vector>
#include <string>
#include <cassert>
using namespace std;

struct Node {
    string val;
    Node* next;
};

struct Queue {
    Node* first;
    Node* last;
};

void initQueue(Queue& q) {
    q.first = nullptr;
    q.last = nullptr;
}

bool isEmptyQ (const Queue &q){
    return nullptr == q.first;
}

void enQueue(Queue& q, string val) {
    Node *newnode = new Node {};
    newnode->val = val;
    newnode->next = nullptr;

    if (isEmptyQ(q)) {
        q.first = newnode;
    } else {
        q.last->next = newnode;
    }
    q.last = newnode;
}

string front(const Queue& q) {
    assert(!isEmptyQ(q));
    return q.first->val;
}

int size(const Queue& q) {
    int i=0;
    Node *cur = q.first;
    for (;cur;cur=cur->next) i++;
    return i;
}

void deQueue(Queue & q) {
    assert (!isEmptyQ (q));
    Node* p = q.first;
    q.first = q.first->next;

    if (nullptr == q.first) {
        q.last = nullptr;
    }
    delete p;
}

void nuke (Queue & q) {
    while (!isEmptyQ(q)) {
        deQueue(q);
    }
}