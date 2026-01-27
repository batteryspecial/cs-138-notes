# Recall the Stack

The Stack is an ADT that supports FIFO. We implemented the Stack using Linked List. Now we can implement the Stack using the `vector` class. We can define an API for the stack operations (push, pop, etc) that is (mostly) independent of the implementation strategy. This means that the client code is (mostly) the same regardless of which implementation you pick, if you design the API carefully enough.

## Complexity of Stack Operations

__Linked List__
1. `push`
    - O(1)
2. `pop`
    - O(1)
3. `peek`
    - O(1)
4. `nuke`
    - O(n)

__Vector__
1. `push`
    - Amortized O(1)
    - Once in a while we need to increase storage O(n) to get more storage.
2. `pop`
    - O(n)
3. `peek`
    - O(n)
4. `nuke`
    - O(n)

Why is everything O(n)? Because we need a deep copy, which is always O(n).

You may ask, why use the Stack if the vector class does the job for me. Why don’t I just use that directly in my main program instead of bothering with defining a special interface.

The answer is that when you design an ADT for use by others (i.e., as part of a library), the interface is the most important part!
- If you change an interface/API after making it public, client code will no longer compile; changes in the client code will be needed to conform to the new interface
- However, if you change the ADT implementation code without changing the interface (e.g., to fix a bug), the client source code itself will not need to be changed or recompiled; you will have to recompile the library

# The Adapter

The stack-vector is an example of what is called an _adapter_. The `stack` ADT has a small, well-understood APi. `vector` has a lot of other functionalities that stacks do not need. 

Designing an interface that provides exactly what clients need, nothing more, nothing less prevents clients from depending on extra structures they do not need.

## Adapter Design Pattern

This is really a bit of design philosophy, if we discover a more efficient way of implementing the stack interface, clients don't need to change their code as long as the interface doesn't change too. Maybe the vector class runs slow on certain types of devices.

The single most important concept in SE is information hiding, or encapsulation. Separate interface from implementation; hide implementation details; have clients depend only on well-designed, unlikely-to-change interfaces.

The interface should be much less likely to change than the implementation details! We are really creating an abstraction for more complex underlying logic.

# Vector or Linked List?

Use the `stack` class in the C++ Standard Library!
- An adapter based (by default) on a deque (which is similar to a vector), and in a style very similar to what we did, so really we should always choose the pre-existing STL library `stack`.
– `stack` supports only 7 methods: empty, size, push, emplace, pop, top, and swap (as of C++20).
– `vector`, on the other hand, supports a total of 29 methods!

## Passing by Reference

The naive functional-style vector-based approach requires a __lot__ of copying.
- Not at all realistic for efficiency
- A realistic implementation in a functional style sometimes require tricks to make things efficient, but we won't go there

# Reference Parameters

By default, parameters are passed by value in C++, just like C. When they are passed, copies are made, changes to these copies do not change the parameters.

We can use pointer parameters if we want to change the values the pointers point to. However, in C++ there is a much better method, called reference parameters.

C++ (and C#) also supports the idea of reference parameters. Put an ampersand after the parameter type in a function declaration. A reference back to the variable in the calling context is made (like a pointer).

Any changes you make in procedure will propagate back to the caller. No need to dereference. Use the variable normally.

Reference parameters can have a `const` return type.

## `const` Parameter

A const reference parameter is a reference parameter that you aren't allowed to change, which may sound semantically useless, but in reality they are more space and time efficient than value parameters, since you don't copy the whole object.

This is the preferred way to pass arguments in C++ if we are not changing the argument. The actual efficiency gain varies in significance based on the argument.

However, you can lie to the user by using the `const_cast()` function, which can override a `const` parameter. 

## "Only Two Beers"

Using a non-const reference parameter is like giving away your car keys to a drunk friend at a frat. If the function might have to change the value of the arugmnet, then use a (plain) reference parameter in the declaration.

Use a `const &arg...` otherwise.

## Reference Parameters and Pointers

Clang does not have reference parameters, however, C++ supports C-style pointers, therefore you do see passing by pointers sometimes in production code.

The C++ approach is to pass objects by reference. 

Also, C backward compatibility sometimes requires using pass-by-value You can use value params for small things (basic types / scalars) like int, double, bool, etc... assuming you don't need changes to propagate back. You can always use a reference param for them too!

## How to Read the Declartion

Read backwards, from right to left.

1. `Employee * const e`
    - `e` is a const pointer to `Employee`.
2. `const Employee & e`
    - `e` is a reference to constant `Employee`.

# Reference Variables

```cpp
// A reasonable use for a reference
Employee & e = emplList[Wloo].find(empNum);
cout << e.getName() << " " << e.getAddr() << endl;

// A pretty useless reference, and likely a bad idea
int x = 13;
int& y = x; // y is another name ("alias") for x. 
            // "x" and "y" are now interchangeable!

y = 36; // Changes value of x!
int *p = &y; // Taking the address of y gives the address of x!
```

What do we see? `y` and `x` share the same memory address.

## Context for `&`

Whenever `&` appears as a part of a type, like `int&`, it means __reference__. Whenever `&` appears in an expression, like `int* p = &x` it means __address of__, or bitwise `and`.

`&&` has a different meeting which we will discuss later.

# Reference Parameters and ADTs

We can now easily switch to reference params in our ADT definitions.

```cpp
// vector-based Stack implementation is now quite reasonable
// No more crazy egregious copying of vector parameters!
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
// Simple impl using a vector; as before
typedef vector<string> Stack;
// Note that we don't need to define initStack or nuke if we
// use vectors as the underlying implementation mechanism
// Rest same as above ...
bool isEmpty (const Stack& s){ ... }
void push (Stack& s, string e){ ... }
void pop (Stack& s) { ... }
string peek (const Stack& s){ ... }
```

Do note changes can now be made to the internals of these Stacks.

# Three Big Types of Variables

1. Global variables are defined outside of any enclosing function/class/struct
    - They come into existence when declared and die at the end of the program
    - We haven't really used them in CS138 (except for named constants, but those probably belong inside a class too)
2. Local variables (incl. params) are defined within a function/method body
    - They come into existence (eventually) when the function is called, and die when their enclosing scope terminates
3. Member / instance variables are a sub-part of a larger variable that is an instance of a struct or class
    - They are born when the instance is created, and die when the instance dies

In C/C++, an __identifier__ (a name you picked, e.g., for a variable or function) is visible from its declaration until the end of the current __scope__.

When a new scope is entered, an __activation record__ (area of storage on the __run-time stack__, also called a stack frame) is created for it. ARs contains storage space for parameters and the eventual return value.

## Scopes of Identifiers and ARs

The truth about when variable scopes begin/end is slightly more complicated.
1. When a new function call is made, an AR with storage for the parameters and return value (if any) is created on the run-time stack
2. As the function executes and declares new local variables, storage is allocated within the AR for them
3. When execution leaves a sub-scope of the function, the storage for any local variables declared inside that sub-scope is deleted
4. At the end of the function call, the return value (if any) is copied back to the calling environment and the AR is deleted.

```cpp
#include <iostream>
using namespace std;
    // Why won't this compile?
    int max (int x, int y) {
    if (x > y) {
        int bigger = x;
    } else {
        bigger = y;
    }
    return bigger;
}
int main (int argc, char* argv[]) {
    cout << max (5, 17) << endl;
}
```

Will the above code compile?
Of course not.

## The Run-Time Call Stack

At any given moment, you might have several scopes open due to nested procedure calls.

If you pause the execution of a program, the run-time call stack will contain an __activation record__ (aka. __stack frame__) for each still-active procedure call in the pending call chain.

When the most deeply nested call completes, the return is copied back to the calling context, and the AR for that call is deleted.

Eventually, all calls will finish, including the original implicit call to main made
by the system, and their ARs will be deleted too.

