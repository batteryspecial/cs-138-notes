# C++ Dynamic Arrays

We're taking a look at how `vector` is implemented under the hood. We are not implementing this using C-style arrays, because they are contiguous chunks of memory.

Random access of elements is always fast (constant time), because it's a simple address calculation. We know element A[i] is located at A[0] + i * "element size" and element A[i+1] is the next one after A[i].

C++ has both (C-style) static arrays and dynamic arrays, although access is unrestricted, which is a source of errors and security concerns.

The C++ standard library also provides classes vector<T> (resizable) and array<T> (fixed size). They provide the same functionality as "raw" arrays with similar performance with index checking and programmatic access to the "extent" at the cost of some performance.

## Static Arrays

C-style arrays.

```cpp
int main() {
    const int N = 5;
    int A[N]; // legal

    int m;
    cin >> m;
    int A[5]; // illegal
    ...
}
```

VLAs are not allowed!

## Dynamic Arrays

Storage is allocated on the heap. Array bound can be a run_tile value, but you need to `delete[]` when you are finished.

```cpp
string* my_alloc(int n) {
    assert(n > 0);
    return new string[n];
}
```

Then you can use the array in main.

```cpp
int main() {
    int N;
    cin >> N;

    int *A = new int[N]; // legal
    string *B = my_alloc(N);

    for (size_t i=0;i<N;i++)
        cin >> A[i] >> B[i];
    
    delete [] A;
    delete [] B;
    return 0;
}
```

Note, the C++ Standard does not specify where the extent of a dynamic array is stored. The array is a pointer to the first element, not the full extent of the dynamic array.

This means we __cannot__ return an array from a function. However, we can return the pointer to the first element.

The system needs to remember how many elements are in the heap-chunk that was allocated for the dynamic array, which will be removed in `delete`.

Know that the extent of the array must be associated with the heap, not the pointer, because the pointer is not specific to that piece of memory. We can't store the extent at the start of the array either, because that would overwrite the first element, which requires hidden math behind every array access.

## Extent

The extent of a dynamically allocated array has to be stored somewhere, but it is not accessible programmatically. Only the compiler truly knows where it is. Don't bother searching for it.

# Variants of the Linked List

The generic "thing" we have been working with to implement our stacks, queues, etc. is called a "linked list". A LL has a special pointer to the head, node instances with a pointer to the next element, and some sort of value.

### Doubly Linked List

Has links to both the next and previous elements. More flexible than a singly-linked list, but at the cost of an extra ptr. The standard library has a `<list>` data structure that implements this idea.

```cpp
struct Node {
    string val;
    Node *next;
    Node *prev;
};

struct DLL {
    Node* first;
    Node* last;
}
```

### Binary Tree

The binary tree has a root node, and each node has two children, a left and a right. Trees can be sorted in some way, although __non-binary trees__ also exist where nodes can have an arbitrary amount of children.

```cpp
struct Node {
    string val;
    Node* left;
    Node* right;
};

typedef Node* Tree;
```

## Lists and Ordering

Thus far our structures are ordered by arrival in some way, we call them ordered lists. We can also create lists sorted by a key value of the element, called a sorted list.

The ordering does not depend on the insertion order. We can imagine that the value stored can be more complex than just a single string.

The __priority queue__ is a hybrid, partly based on arrival and partly based on order. Coming soon to CS138.

### Avoiding Faults

- When you declare a ptr, set it to some meaningful value soon after
    - Newly declared ptrs have random garbage as default initial values
    - Set pointers to nullptr if they're not pointing to something "active"
- Create "state-reporting" functions and defensively use them
    - `printStack` / `toString` method to help in debugging
- Use IO and assertions to check your assumptions about ADT inner states
- Learn how to use a debugger

# Test-Driven Development

All agile approaches put testing at the core of development
- Tests effectively define what "correctness" means for the system
-  Tests are designed along with (or even ahead of) the code

Test-driven development (TDD) is often part of "agile development" processes. This means we develop the tests before we code and we are developing to match the tests. This means we need to keep the tests up to date all the time!

For this reason it is very labor-intensive and often infeasible.

## Testing Techniques

The truth is, you can't test everything. Testing is expensive, we want tests to be effective. Sometimes, we need to do some economic analysis to determine what brings the best ROI.

### Unit Testing

Unit tests assesses the results of individual components, such as a single class or file or a set of closely related functions from a single API.

They often require some technical infrastructure ("scaffolding") to be able to create and run the tests. For example, we have JUnit for Java, GoogleTest, Boost, CPPUnit for C++, Pytest for Python, MSTest for C#, Jest for JavaScript.

### Integration Testing

Integrated tests assesses functionalities at a higher / coarser level, often subsystems comprised of smaller units. Integration emphasizes continuous integration and gradual scaling rather than massive merges.

System-level testing (aka. acceptance testing, end-user testing) is the coarsest level of integration testing; it tests the functionality visible to the external user (Marmoset is an example, comprising of a frontend Submitserver and a backend BuildServer).

<div style="text-align: center; display: flex;">
  <img src="https://assets.cdn.prod.twilio.com/images/MyR86UeunZJcErQJmlEoEwWpAt56uIH2k2mHFqfsA95S2R.width-500_NbXJ1BV.png" alt="Description" style="width: 50vw;">
  <img src="截屏2026-02-03 上午11.49.48.png" alt="Description" style="width: 50vw;">
</div>
