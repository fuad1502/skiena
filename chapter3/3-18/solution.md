- To have O(1) successor and predecessor, each node must store it's successor and predecessor location.
- On deletion, the deleted node predecessor's sucessor is set to the deleted node sucessor. Also, the deleted node successor's predecessor is set to the deleted node predecessor.
- On insertion, while we find a place for the new node, we can keep track of the node with the smallest value that is still larger than the new node (successor), likewise, the largest values that is still smaller than the new node (predecessor). Once a place is found (and the predecessor and successor is found), change the predecessor's successor and successor's predecessor to the new node.

Note 1: the predecessor / successor of a newly inserted node will defintely be on the path going towards the new node location, since the newly added node is a leaf.

Note 2: The successor (predecessor) node of the newly added node is the last node "taking a left (right) turn"
