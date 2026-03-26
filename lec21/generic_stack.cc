#include "generic_stack.hh"

template <typename T>
void Stack<T>::pop() {
    assert (!isEmpty());
    Node* temp = first;
    first = first -> next;
    delete temp;
}

template <typename T>
T Stack<T>::top() {
    assert (!isEmpty());
    return first-> val;
}

template <typename T>
void Stack<T>::print() const {
    Node* p = first;
    while (nullptr! = p) {
        cout << p->val << endl;
        p = p->next;
    }
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return nullptr==first;
}

int main (int argc, char* argv[]){
    Stack<string> s1 {};
    s1.push("alice");
    s1.push("bob");
    s1.push("carol");
    s1.print();

    Stack<int> *ps2 = new Stack<int> {};
    ps2->push(15);
    (*ps2).push(37);
    ps2->print();
    delete ps2;
}