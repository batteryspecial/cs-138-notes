#include <string>
#include <cassert>

using namespace std;

struct Node {
    int priority;
    string v;
    Node* next;
};

typedef Node *PQ;

void PQ_init(PQ& pq) {
    pq = nullptr;
}

bool PQ_isEmpty(const PQ& pq) {
    return (pq == nullptr);
}

void PQ_leave(PQ& pq) {
    assert (!PQ_isEmpty(pq));
    Node* p = pq;
    pq = pq->next;
    delete p;
}
void PQ_first (const PQ& pq, string& v, int& priority) {
    // notice we are finding the first, and the priority!
    assert (!PQ_isEmpty(pq));
    v = pq->v;
    priority = pq->priority;
}

// very similar to insert for sorted LL
void PQ_enter(PQ& pq, const string& v, const int& priority) {
    Node* newNode = new Node {};
    newNode->v = v;
    if (PQ_isEmpty(pq) || priority < pq->priority) {
        // Cases 1-2: insert *as* first element
        newNode->next = pq;
        pq = newNode;
    } else {
        // Cases 3-6: insert *after* first element
        Node* cur = pq;
        while (cur->next && priority > pq->next->priority){
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

void PQ_nuke(PQ& pq) {
    while(!PQ_isEmpty(pq)) {
        PQ_leave(pq);
    }
}
