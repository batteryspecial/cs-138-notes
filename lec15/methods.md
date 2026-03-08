# Defining Methods

We need to provide implementation (definitions) of each method after declaration. Recall the balloon example from last class.
- `Balloon::Balloon()` means the Balloon method (ctor) of no arguments for the Balloon class. We a default ctor, which set the color to grey.
- `Balloon::speak()` is the same, but it's a void const which does not modify the object's member variables.

Now, using the principles of OOP, let's re-create the stack using a class.

Take a look at `oop_stack.hh`.

## Stack as a Class

We must declare all client-facing functions as `public` since classes are by default private. Private now provides an explicit method of hiding the implementation details, which in this case is the vector. Attempting `s1.v.push_back(...)` will result in the error message `member "Stack::v" (declared at line 22 of "...") is inaccessible`.

We instantiate a class just like a struct. A class object can be on the stack or heap, although we need to use `->` to call methods for a pointer to a heap object.

The `Stack` reference parameter is no longer required, everything is by default a reference. Let's see what this means.



Before OOP, our stack implementation using a vector looked something like this.

```cpp
bool is_empty(const Stack& s) {
    return s.v.size() == 0;
}
```

Inside a class method, C++ automatically gives you a hidden pointer called this. Now, the function is a method of the class, and the stack parameter disappears.

```cpp
bool Stack::is_empty() const {
    return v.size() == 0;
}
```

Instead of writing `is_empty(s)`, we can write `s.is_empty()` where the object `s` is implicitly passed as `this`. Internally C++ treats the object like `bool Stack::is_empty(Stack* this)`. The stack parameter still exists, it's just that we don't see it anymore.

So `Stack::size()` can be identically implemented like this.

```cpp
int Stack::size() const {
    return this->v.size();
}
```

They mean the same thing. A const ref method turns into a const method. To summarize, here's a table comparing procedural and OOP approaches to DS implementation.

| Procedural                   | Object-oriented           |
| ---------------------------- | ------------------------- |
| `func(const Stack& s)`       | `Stack::func() const`     |
| stack passed explicitly      | stack is `this`           |
| `const` applies to parameter | `const` applies to object |

We can also ignore the meaning of virtual for now, but please make all your dtors virtual unless told otherwise.

# OOP-Style Hash Tables

Let's implement a hash table by open hashing. This is a vector / array of pointers, each of which points towards some linked structure. We have two private functions this time, the vector holding the Node instances and the hash function (which we probably want hidden).

If we try using this secret hash function the compiler will not allow us. `function "HashTable::hash" (declared at line 57 of "...") is inaccessible`, although this "secret" function we used is actually a terrible hash that nobody will ever use in production.

The table includes the name of a person and their serial number (snum) which is the key.

For HashTable::remove(int snum), we used a sigma double pointer technique. It's actually very interesting how double pointers are in fact, a very elegant solution here to hash table removal.
