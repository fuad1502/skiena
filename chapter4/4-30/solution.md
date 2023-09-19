In the first pass: k/2 * 2n = kn
In the second recursion: k/4 * 4n = kn
Up till the last step: k/2^h * 2^h * n = kn

The number of steps is log2(k), therefore the total complexity is nklog2(k), which is the same as the heap method.
