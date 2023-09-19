We can put the elements into a binary tree, if we found that the element already exist, we simply "stack it".
Since the number of distinct elements is k, the height of the tree would be log(k) and the complexity of this step would be nlog(k).
The next step would be to read out the elements out of the tree in sorted order, which would take n time. Therefore, the total complexity is nlog(k).
