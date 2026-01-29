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

# Towers of Hanoi

In a temple in Hanoi, there are 64 differently-sized disks (rings) stacked on a pole in increasing order of size. The monks must reassemble the rings (in increasing order of size) on a second
pole, using a third pole as a temporary.
- The monks can move only one disk at a time
- No larger disk may ever be placed on top of a smaller disk

The solution is surprisingly simple. Try playing [the game](https://www.mathsisfun.com/games/towerofhanoi.html).

Shift 'n-1' disks from 'A' to 'B', using C.
Shift last disk from 'A' to 'C'.
Shift 'n-1' disks from 'B' to 'C', using A.

```cpp
void hanoi(int N, int src, int dest, int temp) {
    if (N == 0) return;
    hanoi(N - 1, src, temp, dest);
    cout << "Disk moved from " << src << " to " << temp << endl;
    hanoi(N - 1, temp, dest, src);
}
```

## Runtime of Towers of Hanoi

Let H<sub>k</sub> be the number of moves required for k rings.

By looking at the code, we see H<sub>0</sub>=0 and if k>0 then H<sub>k</sub>=2*H<sub>k-1</sub>+1
But can we solve the recurrence relation directly?

H0=0 H1=1 H2=3 H3=7 H4=15 H5=31

Let's cleverly guess that H<sub>k</sub>=2<sup>k-1</sup>.
We solve by induction.

__Inductive Step__
Assume H<sub>k-1</sub>=2<sup>k-1</sup>.-1, try to prove H<sub>k</sub> = 2<sup>k-1</sup>.

Hk = 2*H<sub>k-1</sub>>+1
= 2(2<sup>k-1</sup>-1) +1
= 2<sup>k</sup>-2+1
= 2<sup>k</sup>-1
