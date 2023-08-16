```
f(A, B):
    // create array with elements (time, in/out)
    S = create_array(A, B)
    // sort S according to the key (time)
    sort(S)
    // find time range with maximum person
    max_person = 0
    max_time_range = (0,0)
    n_person = 0
    in_time = 0
    store_in_time = true
    for s in S
        if(s.inout == in)
            n_person++
            if(store_in_time)
                in = s.time
                store_in_time = false
        else
            if(n_person > max)
                out = s.time
                max_time_range = (in, out)
                max_person = n_person
            n_person--
            store_in_time = true
    return max_time_range
```
