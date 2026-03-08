#include "oop_stack.hh"

int main() {
    Stack s1 {}; // created on run-time stack
    s1.push("alpaca");
    s1.push("beaver");
    s1.push("cat");
    s1.push("dog");

    cout << s1.size() << '\n';

    Stack* s2 = new Stack {}; // created on the heap
    s2->push("one");
    (*s2).push("two");

    cout << s1.top() << '\n';
    cout << s2->top() << '\n';

    s1.pop();

    cout << s1.top() << '\n';
    cout << s1.where("beaver") << '\n';

    delete s2; // notice how we have to manually delete s2 since the dtor for stack does not include delete

    //s1.v.push_back("invalid");
    
    return 0;
}