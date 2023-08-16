```
merge_overlap(I):
    H = create_heap(I)
    m = (0,0) // current interval to merge
    while(H.size() != 0)
        i = extract_minimum(H)
        if(i.x > m.y)
            m = i
            L.add(m)
        else
            m.y = max(m.y, i.y)
    return L
```
