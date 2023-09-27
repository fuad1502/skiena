The problem can be re-stated to "Find the location of *jumps* in the array." Where a *jump* is defined as an increase in element value by > 1.
Since we are interested in finding the smallest integer, we are actually interested in the first occurance of a jump. We can do a binary search here.

Evaluate the middle element, if A[i] > i, a jump has occured before this point, search the left half.
If not, a jump hasn't occured before this point, search the right half.

Since, there is no "found check" the search will always fail. But when it does, return the left index, l.

Once we have the left index, the smallest integer is given as A[l-1] + 1. (If l is 0, simply return 1)
