# Tree Terminology
- Root, Child, Leaf, Internal Nodes, Height, Depth

# Binary Trees
- 2 Children
- Inorder Traversal
    - 1,2,3,4,5,6,7
- Preorder Traversal
    - 4,2,1,3,5,6,7
- Postorder Traversal
    - 1,3,2,7,6,5,4

```
4
|
2----5
|    |
1,3  6
     |
     7
```

# Removal

- Perform search to find node to remove.
- If there are children, delete the node and replace it with the subtree that is not nullptr.
- If there are two children find the largest node in the left branch, then move that node to the deleted node.

# Heap

A perfectly complete binary tree where every subelement is smaller than the current node. Heap sort has a loglinear comlexity.
