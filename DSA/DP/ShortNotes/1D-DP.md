## 1D DP


1. Given an integer n, there is a staircase with n steps, starting from the 0th step. Determine the number of unique ways to reach the nth step, given that each move can be either 1 or 2 steps at a time.
   ```
   move one or two : f(i-1) + f(i-2)
   ```
3. A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step.
   To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from any step either one or two steps, provided it exists. Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.
   ```
   one = abs(arr[i]-arr[i-1]) + f(i-1)
   two = abs(arr[i]-arr[i-2]) + f(i-2)
   return min(one,two)
   ```
4. A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k.
   To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.
   ```
   try all possibilities of 1, 2, 3 .... k
   
   for i -> 1 to k:
     mini = Min ( abs(arr[i]-arr[i-k]) + f(i-k) , mini )
   ```
6. Given an integer array nums of size n. Return the maximum sum possible using the elements of nums such that no two elements taken are adjacent in nums.
   ```
    pick and move to next next (or) don't pick and move to next
   ```
5. A robber is targeting to rob houses from a street. Each house has security measures that alert the police when two adjacent houses are robbed. The houses are arranged in a circular manner, thus the first and last houses are adjacent to each other.
   Given an integer array money, where money[i] represents the amount of money that can be looted from the (i+1)th house. Return the maximum amount of money that the robber can loot without alerting the police.
   ```
   similar to #4
   start with arr[0] - answer 1
   start with arr[1] - answer 2
   answer = max( answer1, answer2 )
   ```

   
   
