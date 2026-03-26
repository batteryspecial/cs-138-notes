#include <iostream>
#include <string>
#include <cassert>
using namespace std;

template <typename T>
class Stack {
    public:
        Stack();
        virtual ~Stack();
        void push(T val);
        void pop();
        T top();
        void print() const;
        bool isEmpty() const;
    private:
        struct Node;
        Node* first;
};

template <typename T>
struct Stack<T>::Node {
    T val;
    Node* next;
};