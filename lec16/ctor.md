# Constructors

A constructor is a special kind of method that specifies a recipe for a new instance of the class. The ctor's shorthand is the same as the class name, say _className_. The verbose name is `className::className`.

The ctor specifies what needs to be done to sub-parts when a class is instantiated; and for any given instance a ctor must be called at the beginning of its lifetime. This is also a key difference between C++'s `new` and C's `malloc()`. `new` calls the constructor of the allocated object.

__Are we allowed multiple constructors for a single class?__

Yes. However, they must differ in the arguments they take. This is called __overloading__. These are like alternative recipies, but a client can only choose one. As of C++ there is a feature called __constructor delegation__ that allows constructors to call each other.

Often, we choose to define the __default constructor__, or the ctor that can be called without arguments.

# The Default Constructor

A ctor that can be called without arguments does not mean it has no arguments. If you define a ctor with args where each arg also has a default value in the parameter list, then that is the __unique__ default ctor for that class.

You can define a default ctor yourself, or the compiler can define one for you. There can be at most __1__ default ctor per class.

```cpp
// Class declaration
class Balloon {
public:
    // This below is a different way to define the default ctor;
    // it can be called with no args, or with a single string arg
    Balloon(string colour = "Lyons hunting tartan");
    // We've already defined a default ctor, so the below is illegal
    // Balloon();
    virtual ~Balloon();
    void speak() const;
private:
    string colour;
};

// Default parameter values, if any, are specified once, in the declaration
Balloon::Balloon (string colour) : colour {colour} {}
Balloon::~Balloon() {} // trivial dtor

void Balloon::speak() const {
    cout << "I'm a " << colour << " balloon!" << endl;
}
```

Notice, you can define a default argument inside of the ctor. This syntax might appear 逆天, but it is completely valid.

## The Compiler-Called Default Constructor

As we mentioned, the compiler will make a default constructor if you don't define one yourself.

1. Call default constructor of all sub-parts (class + struct instances).
2. Create sub-parts like `ints`, `floats`, pointers, etc. but they may not be given an initial value, depending on how the object is instantiated.

If you do define other ctors, then the compiler will __not__ define the default one for you. The compiler assumes you choose to not have a default constructor for the class! If you need a default constructor, define it!

As of C++ 11, you can explicitly request the compiler default ctor.

```cpp
class ClassName {
public:
    ClassName() = default;
}
```

## Default Constructors of STL Objects

Objects in the standard library also have their own constructors. For example, the `vector` library allows you to initialize a vector of arbitrary length. It will initialize every element with their default value.

```cpp
vector<int> v1(10);       // init with 0
vector<Node*> v2(10);     // init with nullptr
vector<string> v3(10);    // init with ""
vector<Balloon> v4(10);   // init with "Lyons hunting tartan"
```

Remember, when in doubt, define your own default ctor due to variability in C++ compiler behaviors.

# Inside a Method

```cpp
void Balloon::speak() {
    cout << "I'm a " << this->colour << " balloon!" << endl;
}

int main (int argc, char* argv[]) {
    Balloon b1 {}; // "Lyon's hunting tartan" by default
    b1.speak();

    Balloon b2 {"red"};
    b2.speak();
}
```

The method will invoke the instance's own member variables. In other words, `this`, a pointer to the object in question. You don't need `this`. You can directly write `colour` and nothing will change.

You may ask, without `this`, what will `colour` refer to? The compiler has an explicit lookup order.

1. Is there a local variable of that name (i.e., defined inside the method)?
2. A parameter?
3. A field of the defining class (the case for Balloon::speak())? 
4. A field of an inheritance ancestor of the defining class?
5. A global variable?

# The Initializer

C++ has a special way of initializing arguments, allowing other details to be performed inside the the ctor's scope. Using the initializer list is the default practice in C++.

Any sub-part that is not set using an initializer will be constructed automatically (just before the opening parenthesis of the ctor body) using the default constructor for its type, even if you reset the sub-part's value in the ctor body.

## The Syntax

Call the initializer list like this.

```cpp
Balloon::Balloon() : colour("grey") {}
Balloon::Balloon(string colour) : colour(colour) {}
```

You see, we are using a colon, followed by the `partName(value)`. The partNames must be in the order they were declared in the class, not the order they are arranged in the function parameters.

When you create an object instance, all subparts need to be created too!

For a given ctor, we first process the initializer list. If a sub-part is not initialized, then
- If the part is an object, then we call the default (no arg) ctor for the part's class
- If the part is a pointer, number, or other primitive type, space is allocated for the member variable but the initial value is (likely) random garbage

All parts are constructed after processing the initializer list, before processing the ctor body. The ctor body can then proceed to do any further special initialization that was impossible to do using an initializer.

## Example

Looking at `evil.md`, we see an implementation for the default ctor. There are many ways to correctly implement a default ctor, but some methods are more efficient than others.

__1. Pass by Value and Assignment__
```cpp
EvilGenius::EvilGenius(string name, Monster pet) : name{name} /* + implicit call to "pet{}" */ {
    this->pet = pet; // calls Monster's "copy assgt operator"
}
```

1. The parameter `pet` is passed by value via the copy constructor
2. `pet` is implicitly initialized using the Monster() default ctor
3. The constructor runs its body, calling Monster's copy assgt operator

Total __3__ operations.

__2. Pass by Reference and Assignment__
```cpp
EvilGenius::EvilGenius(string name, const Monster &pet) : name{name} /* + implicit call to "pet{}" */ {
    this->pet = pet; // calls Monster's "copy assgt operator"
}
```

1. `pet` is implicitly initialized using the Monster() default ctor
2. The constructor runs its body, calling Monster's copy assgt operator

Total __2__ operations.

__3. Member Initializer List__
```cpp
EvilGenius::EvilGenius(string name, const Monster& pet) : name{name}, pet{pet} {
    cerr << "Creating an EvilGenius named " << name << " with pet " << pet << endl;
}
```

1. The constructor runs its body, calling Monster's copy assgt operator

Total __1__ operation.

We notice, passing by initialization list automatically fills the object with the correct data, skipping the implicit call to Monster's default ctor.

Another huge reason we favor init lists is because fields can be constants, in which case their value is set at initialization (i.e., just before the ctor body), and it will never change moving forward! Thus, initializing constants using an init expression is the only option.


