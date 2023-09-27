Perform binary search, evaluate each middle element as follows:
if A[i-1] < A[i] and A[i+1] < A[i], return the element.
If not, search the left sub-array if A[i+1] < A[i], and search the right sub-array if A[i-1] < A[i].
