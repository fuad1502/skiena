Using this approach of merging k sorted arrays will lead to worse complexity than what was described in problem 4-28, using the result from problem 4-18.
The complexity of merging k n-elements sorted array is:
```
2n + 3n + ... + kn = (2 + 3 + ... + k) * n = nk^2
```
