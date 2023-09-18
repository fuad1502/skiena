```
second_largest(L):
    H = make_heap_fast(L) // ~ n comparisons
    // +1 comparison
    if (H[2] > H[3])
        return H[2]
    else
        return H[3]

third_largest(L):
    H = make_heap_fast(L) // ~ n comparisons
    // +1 comparison
    if (H[2] > H[3])
        return H[3]
    else
        return H[2]

naive_second_largest(L):
    largest = L[1]
    second_largest = L[2]
    // 1 comparison
    if(second_largest > largest):
        swap(largest, second_largest)
    // + 2 comparison * (n - 2) = 2*n - 4
    for i = 3 to n:
        if(L[i] > second_largest):
            second_largest = L[i]
        if(second_largest > largest):
            swap(largest, second_largest)
```
