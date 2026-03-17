// Brad Lushman's example
#include <iostream>;
#include <string>;
using namespace std;

// POD struct, OK to have public vars
struct Node {
public :
Node (string val, Node *next);
Node (const Node& other);
~Node();
string val;
Node *next;
};

// Does what you expect
Node::Node (string val, Node *next) : val {val}, next {next} {}

// Deep copy here; get a new list!
Node::Node (const Node& other) 
    : val {other.val}, next {nullptr == other.next ? nullptr : new Node{*(other.next)}} {}

// The dtor is pretty subtle here
Node::~Node(){
    delete next; // recursive, kinda
}

void print (Node* q) {
    Node* temp = q;
    while (nullptr != temp) {
        cout << temp->val << " ";
        temp = temp-> next;
    }
    cout << endl;
}

int main (int argc, char* argv[]) {
    Node *n = new Node{"ape",
    new Node{"cat",
    new Node{"elk", nullptr}}};
    print(n);
    Node m = *n; // deep copy ctor
    print(&m);
    Node *p = new Node {*n}; // here too
    print(p);
    delete n;
    print(p); // no seg fault
    print(&m); // no seg fault
delete p;
} // End of main scope: m is deleted and its Nodes are deleted also
