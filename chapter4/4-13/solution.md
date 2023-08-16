```
f(A, B):
    // create array with elements (time, A/B)
    S = create_array(A, B)
    // sort S according to the key (time)
    sort(S)
    max_person = 0
    max_time_range = (0,0)
    n_person = 0
    in = 0
    store_in = true
    for s in S
        if(s[2] == A)
            n_person++
            if(store_in)
                in = s[1]
                store_in = false
        else
            if(n_person > max)
                out = s[1]
                max_time_range = (in, out)
                max_person = n_person
            n_person--
    return max_time_range
```
