We can use the same data structure from problem 3-20. However, since we don't need to support deletion, we don't need to update the number of elements to the left and right of each node while searching for the k-th element. However, we also need to keep track of the total number of elements in the tree.
We can then define median to be:
```
median()
    return f(head, n/2)
```
