This is the exact same problem as 4-13, just worded differently.
In this file, I instead will demonstrate the result of applying the algorithm from 4-13 to the problem instance given.

S = {(10, in), (15, in), (20, in), (40, out), (50, in), (60, out), (70, out), (90, out)}
| iteration | n_person | max_person | in | max_interval      |
|-----------|----------|------------|----|-------------------|
| 1         | 1        | 0          | 10 | (0,0)             |
| 2         | 2        | 0          | 10 | (0,0)             |
| 3         | 3        | 0          | 10 | (0,0)             |
| 4         | 2        | 3          | 10 | (10,40)           |
| 5         | 3        | 3          | 50 | (10,40)           |
| 6         | 2        | 3          | 50 | (10,40) / (50,60) |
| 7         | 1        | 3          | 50 | (10,40) / (50,60) |
| 8         | 0        | 3          | 50 | (10,40) / (50,60) |

So, any points within (10,40) range and (50, 60) range will suffice.

CORRECTION: I should've not returned the max interval for this problem. What I should've returned is a range, (x, y),
where x is the last time a "person" came in, 20 / 50, and y is the time where a "person" leaves after a new max_person
value is reached, 40 / 60. So the returned range should be (20, 40) and (50, 60).
