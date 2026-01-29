# The Queue

A container off data that strictly enforces first in first out (FIFO) policy.

The permitted operations are called enter, leave, first, isEmpty. Maybe a constructor initQueue and maybe a nuke.

## Definitions

More formally, and in a functional style:
- initQueue creates + returns a new empty queue
- enter (enqueue) takes an element enew and a queue q and returns a new queue with the new element at the end
- leave (dequeue) takes a queue q and returns a new queue that’s identical to q except with the first element removed
- first (front) takes a queue + returns (but doesn't remove) (a copy of) the first element: e1
- isEmpty Takes a queue and returns true or false, depending if the queue is empty
- nuke just cleans up ... no observable meaning to the client

```cpp
// We're going to use reference parameters, like real sigmas do
void initQueue (Queue& q) {...}
bool isEmpty (const Queue & q) {...}
void enter (Queue & q, string val) {...}
void leave (Queue & q) {...}
string first (const Queue & q) {...}
void nuke (Queue & q)
```

## Linked List Implementation

The vector implementation is incredibly inefficient at large scales. This is why we can implement Queue canconically using a linked list, but we keep track of the first and the last.

Take a look at `queue_vector.h` and `queue_ll.h`.

# Note on Defensive Programming

Why should we use assertions, if they make our program die?

Use assertions where there is no point in proceeding.
1. Check that your logic/assumptions are correct (check the "representational integrity", which is up to you to get right)
    - If first is nullptr you expect that last will be too
2. Check that "user" is being reasonable (up to user to "behave", not you)
    - Popping an empty stack


## `std::flush`
When you ask to print something to cout or cerr without a final endl, the run-time system doesn't always print that (partial) line right away.

Stopping to print is considered expensive at run-time; instead, the run-time can decide to wait until "later" or until another call to cout / cerr is encountered that does have a flush or endl.

Adding flush to a print statement to cout/cerr causes the line to be printed NOW but without ending the line.

`endl` is equivalent to "end the current output line AND flush"

If you hit an assertion failure or if the program just crashes, that partial line may never be printed at all, which can mislead you when debugging.

When you have diagnostic output statements and if you have any incomplete output statements, you should probably flush them. If not, the error log message might never be printed, giving you an incorrect idea of where you were when the program crashed.

# Blackbox Testing

Treat the functions like an opaque black box that you can't see inside. See the functions, not the implementation details.
- Use the pre and post conditions.
- We want to test the functionality of each operation, but we may need to use several of them.
    - e.g., testing push requires using peek to find out what's on the stack

The good thing is, when you change the implementation you don't need to change the blackbox tests. If you add a new function nothing needs to be changed.

__Examples__
1. Does `isEmpty` work on a newly created stack? On a non-empty stack? On an empty stack that's had elements added and then deleted?
2. Does popping / peeking an empty stack cause the correct error message to print?
3. Do a series of pushes and pops result in the expected element on the top?
4. Does nuke result in an empty stack? Can you reuse a stack after a nuke?

# Whitebox Testing

Whitebox means look inside the implementation and write test cases using your understanding of how it is written.

Coverage and validity are examples of whitebox testing. If you change the main implementation, these tests need to change.

Try to imagine what your test cases are testing for.

__Examples__
What must be true of each Node (that can be checked)?
- What must be true of the first pointer?
- What must be true of the linked list that first points to?

Really, here you are testing linked list properties rather than stack properties, because you are testing the representation (implementation strategy) rather than the specification of the ADT.

Not all things you'd like to check are actually checkable
- There's no way to ask if a C++ ptr has been initialized
- There's no easy way to check if "the final stack is the same as the old one except with the new element added on the front" (push's post-condition)

Something you can check is, does first point to a chain of Nodes that eventually ends with nullptr?

# Locality, Practicality, Efficiency

(Black box) specification and (white box) coverage testing is accomplished by building (a lot of) test suites that are external to the main code base.

Testing evolves as the main codebase gets updated.

Validity checking is accomplished by instrumenting the main code base to check properties of the live data structures as its functions operate. Could cause code bloating. 

If validity checking is done, it's enabled only during active development and debugging. Meaning, in an actual development environment, disable the assertions (maybe `NDEBUG`). Often, validity checking is not done at all in industry.
