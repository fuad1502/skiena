A graph with node degrees of <= 2 can only have the following BFS tree forms:
1. A single node (in the case where the root has degree 0)
2. A long line (in the case where the root has degree 1)
3. Two long line connected at the root (in the case where root has degree 2)
4. A triangle (in the case where root has degree 2, and the leaf node of the two lines are connected through a cross edge)

In the first case, the chromatic number is 1.
In the second case, the chromatic number is 2.
In the third case, also 2.
In the fourth, it can be 2 or 3. It is 2 when the cross edge is on the same level, the chromatic number is 3, otherwise, 2.
