# Standard Outputs

The bit shift operators `<<` and `>>` are overloaded in C++ to provide a simple I/O syntax. They work with other I/O streams including file streams. 

You can also provide your own overloaded definitions to read/print custom classes.

# Variables and Constants

You can declare a variable anywhere, including macros using `#DEFINE`. These work the same as C.    

# Boolean Arithmetic

C++ lets you treat arithmetic (including char) and pointers as having true and false meanings.
- Zero (nullptr) means false
- Non-zero pointers means true

This is illegal in many languages, but supported in C++.

```cpp
if (!p) // Where p is a ptr
if (!n) // Where n is an int
if (n = 0) // Whoops
if (n == 0) // Same as !n
if (0 == n) // A great habit
if (nullptr != p) // Also great
if (0 = n) // Won't compile
```

# size_t

```cpp
#include <iostream>
using namespace std;

// size_t vs. int
int main (int argc, char* argv[]){
    size_t st = 2;
    int i = st;
    while (i > -3) {
        cout << "i = " << i << " st = " << st << endl;
        --i;
        --st;
    }
}
```

## Output
```
i = 2 st = 2
i = 1 st = 1
i = 0 st = 0
i = -1 st = 18446744073709551615
i = -2 st = 18446744073709551614
```

- size_t is an unsigned integer type (i.e., there are no negative values) that is guaranteed to be big enough to store the maximum size of a theoretically possible object of any type.
- In the above example, size_t is an unsigned 64-bit integer, but this is implementation dependent
- Use size_t instead of int for anything that is a "size", e.g., sizeof in C, or the number of elements in a vector or array
- It's common to use size_t instead of int for for loop counters
