- Put all names in a single array
  logn
  with n = 10000
  -> 100
- Put the good customer in one array and the rest in the second array
  P(A) x O(given A) + P(B) x O(given B)
  = 0.6 x (log(0.4n)) + 0.4 x (log(0.4n) + log(0.6n))
  = log(0.4n) + 0.4log(0.6n)
  = 1.4logn + log(0.4) + 0.4log(0.6)
  with n = 10000
  -> 140 - 0.486
  The last two terms does not scale with n, and therefore not significant, as shown with n = 10000.
  The main drawback comes from the fact that 40% of the time, the first array is searched too.
- If it is a linear search, it should be faster:
  0.6 x 0.4n + 0.4 x n
  = 0.64n


