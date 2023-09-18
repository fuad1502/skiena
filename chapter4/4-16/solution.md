```
fewest_segments(S, l):
    sort(S) // using l as key
    last_s = (0, 0)
    new_s = (0, 0)
    found_new = false
    for s in S:
        if(s.l > last_s.r)
            if(found_new)
                R.push(new_s)
                last_s = new_s
                found_new = false
            else
                error()
        if(s.l <= last_s.r && s.r > new_s.r)
            new_s = s
            found_new = true
        if(last_s.r >= l)
            return R
    error()
```
