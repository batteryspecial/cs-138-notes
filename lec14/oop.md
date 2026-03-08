# Programming Paradigms

1. Procedural Programming (C-like functions + variables + structs)
2. Object-Based Programming (classes, methods + instances)
3. Object-Oriented Programming (classes/instances + inheritance/polymorphism + generics)

## Object-Based Programming

Classes and structs have variable sub-parts and procedures that act on their sub-parts.
- Subparts are called fields or member variables
- Such procedures are called methods of the class
    - eg. Define a method push inside the Stack class definition that applies only to Stack instances.

Methods (and operators in C++) can be overloaded. Same method name but different parameter sets. This allows the user to use one method for different purposes in different situations.

Each object is an instance of a class or struct. An object can have a subpart that is an object (or a ptr to an object).

## Object-Oriented Programming


1. Inheritance
- __Classes can extend other classes.__
    - A child class inherits all fields and methods of their parent.
    - A child can add new methods or override methods of their parent.
- Some classes may never have any instances, they may exist only to define the common shapes of descendant classes. These are called abstract classes (abstract base classes in C++).

2. Polymorphism
- __Can treat instances of related classes in a uniform manner.__
    ```cpp
    // Figure is an *abstract* inheritance
    // ancestor of Square
    Figure* f = new Square{5, 15, 0, 0, "red"};
    f->draw(); // Uses Square::draw()
    ```

3. Generics
- __Can parameterize some classes by a type.__
    - For example, `vector<T>` can hold types like `string`, `int`, or `Figure*`.

## Example

Take a look at `cballoon.c`. Would it not be nice to initialize the Balloon colour when we create an instance? Create Balloon-specific operations? Make certain parts of the balloon internal, so only certain functions can access them?

Let's implement the balloon class in OOP, and we will see how this is possible.

As you may see, you can't really mess around with access specifiers. Line 13 is actually copying a pointer, not copying the object. That leads to two pointers owning the same object, which is fine, but then we attempt to directly edit a private variable. In addition, we somehow delete the same object twice, which is just a double free.

If you want to actually copy the object as a pointer you need to call the constructor like this.

```cpp
Balloon* ob = new Balloon {*gb};  // copy constructor
```

# Class Declaration vs. Definition

The declaration of a class specifies its "shape":
- If it inherits from another class
- What data subparts (i.e., fields) it has
- What methods / ctors it supports and their signatures
- If it defines a dtor
- What the access rights are for its fields / methods with respect to other classes (public/protected/private)

The methods/ctors/dtor must still be defined, usually after the declaration. Sometime, very short methods / ctors are defined inline inside the declaration too, but we won't do this. Also, static variables must be defined separately from their declaration

# Some Class Conventions

In C++, we often put the declaration of a class `Flurble` into its own file, usually named `Flurble.h` (preferred), and we put the definitions into a file named Flurble.cc (preferred), or Flurble.cpp or Flurble.C. Of course you need to include `Flurble.h`.

The file name extensions (.h, .cc, etc.) are mostly programmer convention, and aren't (usually) enforced by tools / IDEs. Some tools (e.g., Make) do make assumptions about "what to do with a .cc file vs a .C file". In CS138, we'll usually throw everything into one file; not realistic for real-world systems.

# Defining Methods

We need to provide implementations (definitions) of each method (including ctors/dtor) after their declaration.
- Balloon::Balloon() means the Balloon method (constructor) of no args of the class Balloon
- Similarly for void Balloon::speak(). speak() by itself is only the short name of the function; its full name is Balloon::speak()

You might see this similarly to the syntax of `std::[...]`. These are called namespaces, which we will not go into for now.
