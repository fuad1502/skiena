- Deleting the k-th smallest element require us to find the k-th smallest element. To find the k-th smallest element in a tree, we first need to store the number of elements on the left and on the right of each node.
- Now, to search for the k-th smallest element:
```
if(numberOfLeftElements == k - 1)
    return tree
else if(numberOfLeftElements > k - 1)
    numberOfLeftElements -= 1
    return f(tree->left)
else if(numberOfLeftElements < k - 1)
    numberOfRightElements -= 1
    return f(tree->right)
```
- Now, we need to modify the insert function as follows: when the insertion loop goes through a node to the left of it, add it's initial number of elements to its left, likewise when it goes to right of it.
- Since we already handle the numbeOfLeft(Right)Elements field when searching for the k-th smallest element, delete operation can be kept the same.
