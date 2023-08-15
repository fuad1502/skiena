```
findString(tree, p):
    if(tree == nullptr)
        pass
    else if(prefix(tree.data) == p)
        print(tree.data)
        findString(tree->left, p)
        findString(tree->right, p)
    else if(prefix(tree.data) < p)
        findString(tree->right)
    else if(prefix(tree.data) > p)
        findString(tree->left)
```
