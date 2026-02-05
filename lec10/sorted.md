# The Sorted Linked List

Let's use the same `Node` and creaet a sorted list ADT.

```cpp
typedef SortedList // ... Hmmm
void initList (SortedList & first) {...}
bool isEmpty (const SortedList & first) {...}
bool has (const SortedList & first, string val) {...}
void insert (SortedList & first, string val) {...}
void remove (SortedList & first, string val) {...}
int size (const SortedList & first) {...} // maybe
void nuke (SortedList & first) {...}
```

For most of these linked list operations we need a key, which determines our starting and stopping criterion.

## Insert

__Cases__
1. Empty list
2. Single element list (insert before / after)
3. Multi-element list; insert at beginning
4. Multi-element list; insert in middle
5. Multi-element list; insert at end
6. List already contains value (for each of above cases)

## Remove
1. Empty list (error; assert at beginning)
2. Non-empty list; remove first element
3. Non-empty list; remove middle element
4. Non-empty list; remove last element
5. Element not found (can't tell in advance! when do we stop?)

Fun fact, line 79 was an old bug in the code which caused an error only if you tried removing an entry which doesn't exist and was larger than the last entry.

Linked structures are really hard to get 100% correct. It's common for obscure bugs to be discovered later on, even after the code has worked pretty well for a long time, based on possible but statistically unlikely scenarios

## Complexity of Sorted Linked Lists

#### `has`
- Average case O(N/2) == O(N)
- Worst case O(N)


#### `insert`, `remove`:
- Effectively, they also require a lookup (i.e., a call to has)
- But in essence it is an O(1) operation to adjust a few pointers
- The C++ Standard Library container data structures sometimes return an iterator that points to a middle element

## Where's `size()`?

We could implement a size() method that starts at the beginning of the list and iterates through the whole list, incrementing a counter with each element encountered.

Instead of introducing another O(N) operation, we could include a size in our SortedList ADT that keeps track of size for us, like this.

```cpp
struct SortedList {
    Node* first;
    int size;
}
```

Then `size()` becomes trivial. Remember to initialize size as zero in `initList()`.

```cpp
int size(struct SortedList& first) {
    return first.size;
}
```

## Pre and Post of the Sorted LL

1. __insert__
    - Pre
        - sortedList is sorted
    - Post
        - sortedList is sorted
        - sortedList contains new element
        - sortedList has same elements as before, plus the new one

2. __remove__
    - Pre
        - sortedList is sorted
        - Indicated element present
    - Post
        - sortedList is sorted
        - sortedList has same elts as before, minus the indicated one

# The Priority Queue

In any social media, you probably respond to messages using a priority queue. ou respond to items of the highest priority first; they always take precedence. You only respond to lower priority messages if there are no higher priority messages that are unprocessed.

The priority queue is a queue. However each value has an integer priority. What changes?

`enter` is the same. From the outside, you can't see what happens. `leave` means remove the oldest element from among those with the most important (lowest or highest, depending) priority.

Thus, the PQ is a data container that is both sorted (queues are sorted by priority) and ordered (FIFO within each priority's own queue).

The PQ is actually used in real-world software!