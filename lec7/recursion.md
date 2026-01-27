# Recursion

We have seen this in CS137, no need to teach. Recursion is an elegant and powerful concept for problem solving, a good recursive solution can provide simple solutions to hard problems.

The method of recursion is literally creating a recurrence relation then applying the same logic __inductively__.
1. Trivial base case(s) that can be solved easily and directly, or a case that is known.
2. Reduction operator that makes the data "smaller", closer to a base case.
3. Composition operator that composes the answer to the "smaller" problem to get the full answer, eventually reaching the base case.

## Recursive Binary Search

Often misimplemented.

```cpp
const int KEY_NOT_FOUND = -1;

// recursive binary search
int binary_search (vector<string> v, string key, int imin, int imax) {
    if (imax < imin) {
        return KEY_NOT_FOUND; // base case
    } 
    else {
        const int imid = (imin + imax) / 2;
        if (key < v.at(imid)) {
            // composition of new interval left of current key
            return binary_search(v, key, imin, imid - 1); // imid-1 is reduction
        } 
        else if (v.at(imid) < key) {
            // composition of new interval right of current key
            return binary_search(v, key, imid + 1, imax); // imid+1 is reduction
        } 
        else { // v.at(imid) == key, i.e., "found it"
            return imid; // base case
        }
    }
}
```

## Towers of Hanoi
