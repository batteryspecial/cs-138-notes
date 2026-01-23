# C++ Default / Optional Parameters

C++ allows you to define default arguments for functions. If the user doesn't specify a value in function call, the default value i used.

Note the optional args must all come at the end of the parameter list, or calls to the function are hard to parse. Default arguments are a part of the function's interface, not the implementation. If you are doing compilation, defaults go in the interface file, not the implementation file.

```cpp
#include <iostream> // Filename: defaultPara.cc
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

void printKthToken (int k, string fileName = "default.txt") {
    ifstream infile {fileName};
    assert (infile && k>0);
    string s;
    int i = 1;

    while (infile >> s) {
        if (i == 0) {
            cout << s << endl;
        }
        i = (i + 1) % k;
    }
}

int main (int argc, char* argv[]) {
    printKthToken(3); // reads from default.txt
    printKthToken(3, "flurble.txt"); // reads from flurble.txt
}   
```

# Function Overloading

The cmpiler uses the number and type of arguments to decide which function is being called. The decision is made at compile-time. Overloads must differ in the number of types of arguments, return type is not in name.

For example `>>` and `<<` have been overloaded in C++. You can also overload these operators youself to read interesting data structures.

# C-Style Arrays

We can use C++ arrays in the exact same as C. We must stae the max size and it is a compile-time constant. These are called "C-style arrays". In C, we can dynamically allocate memory using `malloc()` and in C++, we can allocate on the heap using `new`.

```cpp
int A[15]; // OK

const int N = 5;
int B[N]; // OK

int M;
cin >> M
int C[M]; // Illegal, but some compilers support it (VLA)
```

## References to C-style Arrays

References to C-style array elements are unchecked at run-time and therefore potentially unsafe. It should be clear at this point that C++ offers greater stability compared to C.

```cpp
const int N = 15;
int A[N];

for (size_t i=0; i<N; i++) {
    cin >> A[i];
}

for (size_t i=0; i<N; i++) {
    cout << i[A] << endl;
}
A[15] = -37;
```

Is there something wrong with the above program? Yes, it's an index error. Undefined. Yet C++ allows it. This is why C++ is often hated for allowing horrible programming logic.

# The <vector> Library

C++ has a `vector` class that is a safe VLA that can hold any data type. They are possibly less space efficient. Under the hood they are implemented using heap-based arrays plus some resizing magic.

Often considered a better design choice than C-style arrays.

## vector<T>

`vector` is a _container class_ in the C++ stdlib. We need to include the vector library, and you need to specify the type of element it contains.

```cpp
vector <int> grades {};                            // default init size = 0
vector <string> monthName(12);                    // init size = 12
vector <string> stooges {"Larry", "Moe", "Curly"}; // init size = 3
```

## Using <vector> as a Fixed-Length Array

```cpp
vector <string> monthName(12);   
```

The above creates a vector called monthName of 12 (null) strings
- If you only ever want 12 strings, then declare and use as above.
- Note parentheses, not square brackets; also, size can be an integer variable
- If you provide a size N, the array is initialized with N copies of the default value of the element type (0 for numbers, "" for strings, etc.)
- Note: C++11 provides the array class for this kind of usage; use that instead

## Vector as a Stack

Typical use of vector-as-stack; you can grow/shrink it dynamically, as needed.

```cpp
// init size and capacity of zero
vector<string> v {};
v.push_back("hello"); // Adds element onto end
v.push_back("hockey fans"); 

// below is same as "string s = v.at(v.size()-1);"
string &s = v.back(); // Creates a pointer to last element

cout << s << endl;
v.pop_back(); // Removes last element
```

`push_back()` and `pop_back()` causes the size to increase/decrease by one.
- `push_back()` may cause the capacity to increase (typically, by doubling it)
- `pop_back()` typically does not cause the capacity to decrease, but you really don't need to worry about it

## Advantages of <vector>

- v.size() == v.capacity(), and it's stable (static)
    - size/capacity can be managed explicitly by resize()/reserve(), but typically aren't needed
- Access elements directly via [ ] or at()
    - Typically do not use operations push_back(), pop_back(), or back()
- At any given moment, you're using all of the available element slots in your vector
- Please consider using an instance of the class array

Number of active elements vary dynamically over the lifetime of the vector. Pushing an element is usually constant time but for big vectors it may run in linear time (called amortized linear time).

## <vector> API Reference

See [the C++ reference](https://cplusplus.com/reference/vector/vector/).

| Expression / Method | Description |
|---------------------|-------------|
| `v.at(i)` | Returns the `i`-th element (bounds-checked access) |
| `v[i]` | Returns the `i`-th element (unchecked access) |
| `v.size()` | Returns the number of elements in `v` |
| `v.capacity()` | Returns the number of elements `v` currently has space allocated for |
| `v.empty()` | Returns `true` iff `v` has no elements |
| `v.resize(n)` | Resizes `v` to exactly `n` elements, deleting or padding as needed |
| `v.reserve(n)` | Ensures capacity is at least `max(n, oldCapacity)` |
| `v.push_back(...)` | Appends an element to the end of `v` (increases capacity if needed) |
| `v.emplace_back(...)` | Constructs and appends an element at the end of `v` (often more efficient than `push_back`) |
| `v.pop_back()` | Removes the last element of `v` |
| `v.front()` | Returns a reference to the first element of `v` |
| `v.back()` | Returns a reference to the last element of `v` |
| `v.begin()` | Returns an iterator to the first element of `v` |
| `v.end()` | Returns an iterator to one past the last element of `v` |

## Example

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main (int argc, char* argv[]) {
    vector<string> v;
    v.push_back("hello");
    v.push_back("there");
    v.push_back("world");

    for (size_t i=0; i<v.size(); i++) { // Naïve way to iterate
        cout << "v[" << i << "] = \"" << v.at(i) << "\"\n";
    }

    v.pop_back();
    v.pop_back(); 
    v.push_back("eh");

    for (auto e : v) { // This is less typing, and encouraged!
        e += ", eh"; // Changes local variable e but not array elt
        cout << e << endl; // e was a *copy* of current *elt*
    }

    for (auto &e : v) { // Also encouraged, if you want to change v
        e += ", eh"; // Changes vector element (e aliases it)
        cout << e << endl // e is/was an *alias* for current *elt*
    }
}
```

What would happen if we did the second loop after the third loop? We would get ", eh, eh" since the third loop changes the variable "e".

