##### Subset sum equals to target
1. Given an array arr of n integers and an integer target, determine if there is a subset of the given array with a sum equal to the given target.
```
pick or not pick
```
##### Partition equal subset sum
2. Given an array arr of n integers, return true if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal else return false.
```
s1 + s2 = totalSum
check if totalSum is even and a subset sum equals to totalSum/2
```
##### Partition a set into two subsets with minimum absolute sum difference
3. Given an array arr of n integers, partition the array into two subsets such that the absolute difference between their sums is minimized.
   ```
   s1-s2 = diff
   s1+s2 = totSum
   s2 = totSum - s1
   diff = s1 - (totSum-s1)
   diff = abs(2*s1 - totSum)

   s1 varies from 1 --> totSum
   for each s1 between 1 --> totSum:
     check if s1 exists and then calculate the diff using above formula.
     update the minDiff 

   checking s1 exists or not:
   - calculate dp for subset sum equals to totalSum.
   - dp[n-1][i] tells whether the sum i exists in the arr[0...n-1] or not.
   - to check if s exists or not in array: dp[n-1][s] has to be true

   calculate the last row using space optimiatization technique with prev and curr rows.
   ```
##### Count subsets with sum K
4. Given an array arr of n integers and an integer K, count the number of subsets of the given array that have a sum equal to K. Return the result modulo 109+7.
```
pick or not pick and return sum of choices.
pick only when the required sum >= arr[i] : necessary for tabulation otherwise it may goes out of bound.
```

##### Count partitions with given difference
5. Given an array arr of n integers and an integer diff, count the number of ways to partition the array into two subsets such that the absolute difference between their sums is equal to diff. Return the result modulo 109+7.
   ```
   s1-s2 = diff
   s1+s2 = totalSum
   s1 = (diff+totalSum) / 2
   
   Count subsets with sum s1
   ```
##### Target sum with +/- evaluation
6. Given an array nums of n integers and an integer target, build an expression using the integers from nums where each integer can be prefixed with either a '+' or '-' sign. The goal is to achieve the target sum by evaluating all possible combinations of these signs. Determine the number of ways to achieve the target sum and return your answer with modulo 109+7.
   ```
   s1 = sum of elements with + sign
   s2 = sum of elements with - sign
   targetSum = s1 - s2
   totalSum  = s1 + s2
   s1 = (targetSum+totalSum)/2

   Count subsets with sum s1
   ```
   
  
