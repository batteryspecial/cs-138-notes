# Inheritance and Abstraction

From last time, we discussed the creation of _abstract classes_ which define the instance variables and methods that will be common along their descendants. We like to call these _parent classes_ or _abstract base classes_, abbreviated ABC. However, we never create _instances_ on ABCs! They are just a means of design.

In contrast, we implement specific designs in _concrete classes_ which inherit the properties of an ABC. They might add new instance variables and methods, or `override` existing methods in a way that fits them without leaving the scope. We create instances of these concrete child classes. By definition, concrete classes do not have abstract methods.

Note, sometimes, the parent class only provides the empty shell of a method (base class with `= 0` or `= default`), expecting children to provide a proper definition. These are called abstract or _pure virtual_ methods.

ctors and dtor of the parent are not inherited, but they are invoked! Each child ctor should call a parent ctor in an initializer. Parent's dtor is invoked automatically by child's dtor (after the child dtor is finished executing). Also, make sure that dtors are declared as virtual when you have inheritance!

```cpp
#include <iostream>
#include <string_view>
class Shape {
public:
   virtual void draw() const = 0; // Pure virtual function
   virtual ~Shape() = default; // Always make base destructors virtual
};
class Circle : public Shape {
public:
   void draw() const override {
       std::cout << "Drawing Circle\n";
   }
};
int main() {
   Shape* s = new Circle();
   s->draw(); // Calls Circle::draw via dynamic dispatch
   delete s;
}
```

## Designing Inheritance

Inheritance naturally creates a tree, but designing an inheritance tree takes a lot of time. In the previous lecture, I tried providing a design for the Wither Blades, and even that may not be optimal in consideration of other game factors.

There is no known procedure to design inheritance trees. Usually, we do not get the big picture right on the first try. Rather, we continue to iterate and make changes moving forward. This is not a programming question, but a mindset question.

Many programmers get stuck on an existing path and fail to step back and consider alternatives. Let's say you are facing this tricky bug with no apparent origin. Maybe take a look at other files and directories.

## Polymorphism

One of the major consequences of inheritance is being able to treat similar objects the same way. We call this __polymorphism__. For example, regardless of what kind of deployable you have (Powerflux Orb, Plasmaflux Orb, SOS Flare) and whatever kind of ability weapon you have (Hyperion, Spirit Sceptre, Glacial Scythe) you can use the `->deploy()` method on any deployable and `->useAbility()` on any magic weapon.

Obviously these examples I gave are from Hypixel Skyblock. Hopefully you get my point.

## Static and Dynamic Pointers

A ptr to a parent class `P` can point to itself (if not abstract) or an instance of `C` where `C` is any descendant of `P`.

```cpp
DeployableOrb *deployedFlux = new PlasmaFlux {.duration=1000000, .utils=plasmaflux_base}
```

For a pointer, its _static type_ is the type it was declared to. Its _dynamic type_ is the type of object it is currently point to (or nullptr). Thus, the dynamic type of a non-nullptr object is always a descendant (or equal) to its static type.\

### Specifics of an Inheritance Tree

We can create hierarchies (trees, usually) where internal nodes represent common functionality and leaf nodes represent concrete specializations. 

We can put commonalities like "deal magic damage" into an ABC then declare the common parts for every descending magic weapon, even if the exact way the magic damage will be dealt is very different.

# An Inheritance Design Example

We want to design a hierarchy of geometric figures that could be used by a drawing tool we are creating.
- We'll start with just Circles and Rectangles.
- They both have a colour and an [x,y] location.
- Circles also have a radius, and Rectangles have a width and height.

Our drawing tool will want to be able to treat all Figures in the same way sometimes, like keeping them in the same vector, ordered by relative position to the top right of the screen.

We will start by implementing the base class in `figure_v1.hh`.

## Observations

1. What is `protected`?
    - The `protected` keyword is an access modifier that turns a method into a family secret. Public to descendants but private for outsiders. Useful for implementing the API for the family.
2. Why do we protect the constructors of `Figure`?
    - Because `Figure` is an abstract base class. There is no reason we should be initializing it. Children may decide to use it for their purposes, but an external client should not be able to access its ctors.

## Virtual Declarations

The `virtual` keyword means "__I expect this method to be overridden by a descendant class; the run-time system will always check to make sure the correct implementation is used for any caller__".

No problems if overriden, as long as it isn't pure virtual. It would be safe to declare all methods are virtual, but the compiler would have to track down every single pointer to find a correct implementation.

A non-virtual function means, "__I do not expect this method to be overridden by a descendant class; at compile-time I will hardcode this method body as the one to be used by any caller__". It is more efficient to let the compiler know if you are sure it will not be overriden, then the compiler can hard-core address instead of doing a runtime lookup.

As we design the child classes, we also need to worry about
- Parts of the children that are not in the parent (e.g., radius)
- Methods declared as pure virtual in the parent that will need to be defined in the child

### Why are dtors Virtual?

Great question. Not always. We do this mainly for abstract base class to be safe.

Let `C` be a child of `P`. We know that `P*` can point to an instance of `C`. Let's consider we allocate a static type `P`, dynamic type `C` class on the heap.

If we delete that variable, we are calling `P`'s dtor. But we aren't really calling the right dtor, are we? Because the dynamic type of the variable is `C`, not `P`.

### ABC Constructors

Recall design `figure_v1`. It works, but it could be cleaner. The question comes that we asked earlier. If an ABC cannot be instantiated, why does `Figure` have ctors?

To add on to our prior explanation, the descendant classes need a build receipe for common parts defined in the parent. This is why we make them protected, because why would anyone else need this ctor exclusive to `Figure`?

It only makes sense to make the ctor protected. A secret shared within a specific inheritance hierarchy. __#OTF__

## Ctors and Inheritance

If you inherit from a class, the "parent parts" have to be initialized. Usually, you will make an explicit choice of which parent ctor to call as the first element in the initializer list, like this.

```cpp
Circle::Circle(string colour, int x, int y, int radius) : Figure{colour, x, y}, radius{radius} {}
```

If you don't call a parent's ctor in the initialization list, then an implicit call to the ctor of no args is made for you automatically. This call to the parent ctor is executed first by default, before any other initialization.

Can we make the fields of Figure private?
- Design-wise, it would be great if we could do that!
- Descendant classes could access those parts via (possibly) protected constructors / accessors.

Here's an idea! Let the ABC manage everything. This is a great goal, but we need a good design process to figure things out.

## Don't Repeat Yourself

If you have something interesting to express in a software design, find a way to do it in only one place! So don't copy and paste procedures / methods from one place in the design to achieve "similar" functionality elsewhere.

If you have a set of objects with similar but not identical behaviors, put them under an ABC!
1. Group the common parts in the ABC
2. Define Child classes, and implement your differences.
3. Any instance of any child class can be treated as if it were an instance of the parent (polymorphism)!

Using this, let's define the Circle in `circle_v1.hh`.

## Child Responsibilities

You need the public in `: public Figure` or else you get private inheritance.

Let's see what we did, and what a child class needs to do.
- Redeclare parts that are new or being overridden
- Don't repeat x, y fields or setPos, getPos methods
- Repeat declarations of any inherited virtual methods (add override)
- `override` causes the compiler to sanity check that you are indeed overriding an inherited function that's declared as virtual in the parent (i.e., check that the name, parameter types, etc. are the same in the parent)
- Need to list all of your ctors and dtor (if using one).
- Technically, you don't inherit these from your parent, but you can call one of the parent's ctor in your own ctor as an initializer.
- In fact, each child ctor __should__ call a parent ctor in their initializer list first!

Note that x, y, and colour are part of the parent Figure, and that you can't use initializers for inherited subparts directly. You need to either initialize them by calling a `Figure` ctor that initializes them (what we did) or setting them in the ctor body (uncommon).

For example `Circle::draw()` accesses the x and y fields of Figure, so they can't be private in the parent, but they are protected, so `Circle` can access them!

## Design Inconsistency

Inconsistencies. Sounds easy to avoid, actuall a super tricky question, even for trivial examples like these. Let's see the example `rectangle_v1.hh`. In `Circle`, we added the `radius`, and hence we used a getter / setter pair.

Now `getRadius()` returned an `int` instead of a reference parameter because it is a single variable. That is no longer the case for `Rectangle`. How do we return two variables? We could split `getSize()` into a `getX()` and `getY()`, or we can create our own coordinate system, say, by creating `struct Rectangle::2DCoords`.

Then should `getSize()` be instead consistent to one parameter? Should we promote the implementation to the parent class? We should probably change `getSize()` in `Circle` to take in a reference parameter as well, but that feels weird.

Do you see the complications that arise from such a simple example? Whatever feels natural for one child is not what feels natural for another. Inconsistency is inevitable; to notice inconsistency is the key, because doing what feels natural can lead to disaster.

Having many eyes on an issue can lead to a solution that gives the best outcome for everyone.

We have everything put together for you nicely in `figure_v1.cc`, demonstrating the core concepts of inheritance and polymorphism, as well as a neat range-based for loop, which we will get to.

Don't worry, there will be a _v2_. Next, we will examine more advanced design patterns in our hierarchy.

# Design Patterns

Design patterns originates from a foundational book in object design, _Elements of Reusable Object-Oriented Software, by Gamma, Helms, Johnson, and Vlissides, pub. by Addison-Wesley, 1994_.

This is still the most influential book on object-oriented design, although it is kind of outdated. Design patterns are __reusable solutions__ to common problems.

We already faced a design pattern, called the adapter. We take an existing functionality and implement our own adaptation of it.

Design patterns are again, an abstraction.

# The Iterator

We have a data container whose implementation is convoluted. What if a client wants to visit each element in turn? Could we have a general method to iterate through any data container?

C++ has a general-purpose library of generic classes and functions called the Standard Template Library (STL).

1. Generic containers that take an element type as a parameter (e.g., vector, list, deque, map, set, stack, queue).
2. Kinds of iterators that can navigate through elements.
3. Algorithms that take a begin-end iterator pair and perform some operation on the elements in that range (eg. sort, random_shuffle, next_permutation).

## Optimal Iterator Design

Have the data container itself provide an iterator API that allows for abstract navigation through its elements.
- begin() points to first element
- ++ advances to the next element, repeatedly
- end() points after the last element or is null

The iterator variable is often implemented as a pointer, so you may deference it to access the element.

Even better, the details of the operations `begin()`, `operator++`, and `end()` are implemented by the container class itself, which already knows the details of the container.

## DIY Iterators

All STL containers define forward iterators (clients can change element values) and const forward iterators (cannot change element values.)
- `vector` supports forward, backward, and random access iterators
- `list` supports forward and backward, but not random access iterators
- `unsorted_set` supports forward iterators only (despite being unsorted)

Instead of trying to guess the type of the iterator, we can use the `auto` keyword to let the compiler interpret the type of the iterator.

Instead of trying to iterate using an index-based for loop, we can also use a range-based for loop.

```cpp
for (auto &s : v) {
cout << s << endl;
}
```

We are making a reference to all elements of `v`. We could remove & from `&s` to set variable s as a copy of v's k<sup>th</sup> element.

## Specialties of Range Loops

Range-based for loops can be used to walk through any class Flurble that has the following properties.
- Flurble has methods `begin()` and `end()` that produce iterators.
- The iterator supports prefix `operator++`, `operator!=`, and unary `operator*`

The range-based for loop works for usual containers from the C++ Standard Library, like vector, map, list, deque, etc.

Also works for classes you design yourself, if you define them properly.

## Kinds of Iterators

Plain old vanilla iterators take you forward thru a collection of data using `++`.

1. `const` iterators, where you promise not to change the collection / elements.
    - In C++ 11, use `cbegin()` / `cend()` instead of `begin()` / `end()`
    - Why bother? Extra safety, and de facto documentation to code reader
2. Reverse iterators start you at the last element, and `++` takes you backwards.
3. Bidirectional iterators can go backwards by decrementing the iterator (`vi--`) or forwards by using `vi++`.
4. Random access iterators (eg. for navigating vectors) allow you to access any elements in the container in no worse than amortized constant time.
    - Random access iterators are necessarily also bi-directional.

### Random Access Iterators

Random access iterators extend bidirectional iterators by supporting
- Constant-time arithmetic (+, -, +=, -=)
- Constant-time distance computation
- Subscript operator ([])
- Relational comparisons (<, <=, >, >=)

They behave like pointers in terms of navigation but do not guarantee that elements are stored contiguously in memory.

If `vi` is a random-access iterator, then `vi[3]` (or `vi+3`) gets you access to the third element after the one currently pointed to by iterator `vi` in no worse that amortized constant time.

Since `vi` is an iterator, you can get there eventually by just incrementing it three times, but perhaps not in ACT in the general case.

For example, iterators for vectors are random access, as you can get to the third element from here by a simple address calculation.

The C++ standard requires that vector elements be stored contiguously. On the other hand, iterators for STL lists are not random access. 

To get to k elements from the current one, you have to follow k pointers. Similarly, maps are implemented as red-black trees, so you can't jump directly to the third element from the current one.

Thus, iterators for list, map, and set do not support at() or operator[].

## Erase

Some containers are based on iterators. For example, `erase()` removes an item.

```cpp
// erases item 0; returns iterator to first element
// after the erase
auto it = v.erase(v.begin());

// erases item 3 (i.e., 4th item)
it = v.erase(v.begin() + 3); // must be random access

// erases item pointed to by it
it = v.erase(it);

// erases last item
it = v.erase(v.end() - 1);
```

To conclude, the three big question for an iterator.
1. Where's the first element?
2. How do I get to the next element?
3. How do I know when I'm done?
