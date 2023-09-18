a. Max heap is faster if accounting for construction time, if not, then both is equally fast. Constructing it require O(n) time, while finding the maximum require constant time. While sorted array require O(nlogn) time for construction, with also constant time in acquiring the maximum.
b. Heap cannot be indexed, so essentially require to list out all the elements (nlog(n)), remove the number to be deleted, then recreate the heap (nlog(n)). While sorted array can do it in just O(n) time. So, sorted array.
c. Max heap is faster to construct, as explained in point (a).
d. Sorted array, constant time. Finding the minimum in a max heap essentially require to lit out all the elements (nlog(n)).
