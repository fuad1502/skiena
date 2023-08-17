```
merge_k(L, k):
    // construct heap of k lists, with the comparison function: L[i].top() > L[j].top() 
    heap = construct_heap(L, k)
    for i from 1 to n
        R.add(heap.max().pop())
        heap.bubble_down()
```
