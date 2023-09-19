Key: The distinct integers must be less than n^1/3.
So, we can do an exhaustive search without making it a quadratic complexity function:
```
test(n):
    count = 0
    for i = 1 to n^1/3
        for j = i + 1 to n^1/3
            if(i^3 + j^3 == n)
                count++
    return (count >= 2)
```
The complexity is therefore n^2/3

Generating all Ramanujan number between 1 to n:
```
generate(n)
    for i = 1 to n
        if(test(i))
            append(i)
```
So, the complexity is:
1^2/3 + 2^2/3 + ... + n^2/3 < (1 + 2 + 3 + ... + n)^2/3 = O(n^4/3)
