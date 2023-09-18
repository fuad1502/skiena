```
sort_tricolor(A):
    // put all red elements to the left
    red_place_idx = 1
    for i = 1 to n:
        if(Examine(A, i) == red):
            Swap(A, i, red_place_idx)
            red_place_idx++
    // put all blue elements to the right
    blue_place_idx = n
    for i = n down to red_place_idx:
        if(Examine(A, i) == blue):
            Swap(A, i, place_idx)
            place_idx--
```
