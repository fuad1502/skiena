- Modify insert to update the dictionary maximum and minimum value with every new value inserted, if the new value is larger than maximum or smaller than minimum.
- Modify delete so that if maximum or minimum is deleted, find new maximum or minimum. This will not change the deletion complexity, because finding new maximum and minimum and the deletion operation itself are all O(logn)