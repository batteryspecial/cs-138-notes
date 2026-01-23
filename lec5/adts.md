# Examples of ADTs

![adts](https://media.geeksforgeeks.org/wp-content/uploads/20190828194629/ADT.jpg "funny")

Mathematically, we think of sets and maps being unordered/unsorted by default. The original implementation of sets and maps was for ordered implementations.

There is a way of implementing unsorted sets/maps that is much more efficient than the sorted implementation. The `unordered_set` and `unordered_map` was added in C++11.

## Abstraction

There may be multiple ways to implement a given ADT, but the point is the abstract specification stays the same. Often, a programming language will provide an interface around ADTs. The interface enforces a limited access of clients to internal details, effectively __hiding__ the data.

For example, interface of Stack supports `push` and `pop` operations, but not `at`. C++/Java/C# provide strong language-level support for building interfaces via `class` definitions. C is moreso structure/imperative-oriented.

# Data Structures as Containers

Many, but not all, ADTs are primarily data containers. They keep a collection of data of a particular kind organized for a practical purpose, depending on their methods.

Data containers can contain just about any kind of data! For now, we'll assume that elements are strings. When we explore the OOP capabilities of C++, we will know how to define generic containers that can hold any kind of element kind

## Style of ADTs
Initially, we are going to use a functional paradigm to create our ADTs C-style. This is clean mathematically, but sometimes inefficient if implemented naively due to needless parameter copying ().

Then, we'll use a more C-like procedural model using the C++ feature of reference parameters.

The general format of an ADT operation in this style is
```cpp
// pass in the ADT as a param, get a new one as a result for mutator ops
newADT operationName (oldADT, otherParams)
```

# The Stack ADT

An ordered container of data the enforces the LIFO (last in first out) principle.
- Permitted operations are `push`, `pop`, `peek`, `isEmpty`
- Plus a constructor, which we will call `initStack` for now
- Plus a destructor, which we will call `nuke` for now

Sometimes, `pop` and `peek` are combined into one operation, and returns the value removed.

## Specifications

- initStack (no args) creates + returns a (new) empty stack to the caller
- push takes stack s and an element enew and returns a new stack that’s identical to s except with the new element on "top": enew e1 ... eN
- pop takes a stack s and returns a new stack that's identical to s except with the top element removed: e2 ... eN
- peek takes a stack and returns either a copy of or a refence to the first element: e1 (but doesn't remove the element from the stack)
- isEmpty takes a stack and returns true or false, depending if the stack is empty: i.e., does N=0

__initStack() -> stack__
- Preconditions
    - True (assuming we have enough memory)
- Post
    - Returned a new, empty stack.

__isEmpty(stack) -> boolean__
- Preconditions
    - True
- Post
    - Returns true if empty, false if not.

__push(stack element) -> stack__
- Pre
    - True
- Post
    - Returned stack with new top element.

__pop(stack) -> stack__
- Pre
    - !isEmpty
- Post
    - Returned stack e<sub>2</sub> ... e<sub>N</sub>

__peek(stack) -> element__
- Pre
    - !isEmpty
- Post
    - Returned value is a shallow copy of e<sub>1</sub>

__nuke(stack) -> stack__
- Pre
    - True
- Post
    - Returnes an empty stack; old nodes deleted

## The Linked List Implementation

First interesting design question. What data type (parameter/return type) should we use to model a stack that is implemented as a linked list?

Recall our linked list from the other day:
- We don't need a ptr variable on the stack for each element; instead, we keep a ptr to only the first element, and then every Node instance (on the heap) has a ptr to the next element
- We just have to keep track of a single Node*.

### Push

If we want to push a new element on to the front of the list, then the first ptr will need to be reset to point to the new Node we create. If we change the first parameter inside the body of push, the effect will not propagate back to the caller. What is the fix?
1. Use C++ reference parameters
    - A good idea! ... but, we're not quite there yet (soon!)
2. The object-oriented approach:
    - Define a class with methods push, pop, etc.
    - An even better idea! ... but we'll do this later in the term
3. The functional approach:
    - Return the new value of first as the value of push

Please see `stack.cc` for the linked list implementation of the __stack__.

### Example
```cpp
Stack initStack () {...}
Stack push (Stack s, string val) {...}
bool isEmpty (Stack s) {...}
Stack pop (Stack s) {...}
string peek (Stack s) {...}

int main (int argc, char* argv[]) {
    Stack s {};
    s = initStack();
    s = push(s, "alice");
    s = push(s, "bob");
    cout << peek(s) << endl;
    s = pop(s);
    cout << s << endl;
}
```

### ADTs and the Stack

ADTs have an explicit interface/API to separate out the high-level functionality that clients should see from the low-level details that the implementor must be deal with.
- The implementor writes the "dirty" code that implements the low-level details of the API functions (push, pop, etc.) using pointers, nodes, library data, structures like vector, etc.
- The client writes "clean"/abstract code elsewhere in the system (e.g., in main) that uses the high-level API functions of the interface.

### Copy Semantics

The C-like programming model provides only weak support for programmer-defined abstractions.
- In this design, we're just renaming a pointer type with a fancy name; C doesn't give us the power of real customizable type creation, like OOP does in C++
- Defining how new objects are created, (re)defining what assignment means
- We need C++-style structs / classes to do the job properly

### On the Use of <cassert>

The assert is a kill switch for the program. Note that in the stack case, the use of assert is part of the normal program logic. If we were to ignore the assertion at run time (we'll discuss why that might happen in a minute), then the program would have a glaring bug here; a seg fault if you're lucky!

We can enable the `g++ -DNDEBUG myprog.cc` macro to disable assertions.

### The Interface and Implementation.

Take a good look at the interface of the various stack operations.
- It's possible to understand how to use a stack by simply studying the interface (if there's enough detail specified by comments)
- The actual details of the implementation don't matter to the client much as long as they do the job correctly
- We will see how we might implement a stack differently while still using the same interface
- Later we will use an OO style to change the syntax slightly but preserving the ideas

## A Vector-Based Implementation
