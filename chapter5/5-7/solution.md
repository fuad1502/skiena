Note that if A(i,j) > e, then the element must be located at A(x,y) with x <= i and y <= j. Respectively for A(i,j) < e.
Therefore, we can reduce our search to n^/4 or 3^n/4 from n^2.
Therefore, in the worst case, the complexity becomes O(log~4/3~(n)).
