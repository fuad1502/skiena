```
fun create_tree(preorder, inorder)
    root = preorder[0]
    root_idx = inorder.find(root)
    left_inorder = inorder[0:root_idx]
    left_preorder = preorder[0:root_idx]
    root->left = create_tree(left_preorder, left_inorder)
    right_inorder = inorder[root_idx+1:]
    right_preorder = preorder[root_idx+1:]
    root->right = crete_tree(right_preorder, right_inorder)
    return root
```
It is not possible if only given the preorder and postorder. For example, the following two trees:
```
1
 \
  2
```
and
```
  1
 /
2
```
Have the same inorder ([1,2]) and preorder ([2,1]).
