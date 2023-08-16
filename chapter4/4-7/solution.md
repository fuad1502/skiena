```
h_index(A):
    sort_ascending(A)
    for i from 1 to size(A)
        if(A[i] == i)
            return i
        else if(A[i] < i)
            return i - 1
```
