### Dutch National Flag Algorithm
Given an array consisting of only 0s, 1s and 2s, sort the array.

* Two-Pass Algorithm:
- Traverse the array once and keep track of the count of 0s, 1s and 2s encountered.
- Now traverse the array again and overwrite the array starting from the beginning, first with 0s, then 1s, and finally all 2s.

##### Dutch National Flag algorithm or Three-way partitioning
* Maintain three indices low = 0, mid = 0, and high = N-1, where N is the number of elements in the array.
1. The range from 0 to low denotes the range containing 0s.
2. The range from low to mid denotes the range containing 1s.
3. The range from mid to high denotes the range containing any of 0s, 1s, or 2s.
4. The range from high to N-1 denotes the range containing 2s.
* The mid pointer denotes the current element, traverses the array while mid<=high i.e we have exhausted the search space for the range which can contain any of 0s, 1s, or 2s.
1. If A[mid] == 0, swap A[mid] and A[low] and increment low and mid pointers by 1.
2. If A[mid] == 1, increment the mid pointer by 1.
3. If A[mid] == 2, swap A[high] and A[mid] and increment mid by 1 and decrement high by 1.
4. The resulting array will be a sorted array containing 0s, 1s, and 2s.

