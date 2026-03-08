#include <iostream>
#include <cassert>
#include <vector>
#include <string>

using std::string, std::vector, std::cout;

class Stack {
    public:
        Stack();
        virtual ~Stack();

        int where(string s) const;
        bool is_empty() const;
        string top() const;
        int size() const;

        void push(string s);
        void pop();
    
    private:
        vector<string> v;
};

// Method definitions; often in a different file (.cc), but we'll use the .h file for now
Stack::Stack() {}
// A destructor is automatically called when the stack goes out of scope, but a vector on the stack gets collected anyways, hence our destructor is an empty function. If a class owns stuff on the heap, it must be explicitly released it in the destructor using delete[].
Stack::~Stack() {}

bool Stack::is_empty() const {
    return (0 == v.size());
}

void Stack::push(string s) {
    v.push_back(s);
}

int Stack::where(string s) const {
    int i = 0;
    for (const string& elt : v) {
        if (elt == s) return i;
        i++;
    }
    return -1;
}

void Stack::pop() {
    assert(!is_empty());
    v.pop_back();
}

string Stack::top() const {
    assert(!is_empty());
    return v.back();
}

int Stack::size() const {
    return v.size();
}
