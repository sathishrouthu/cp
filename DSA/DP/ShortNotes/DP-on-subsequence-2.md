##### 0 and 1 Knapsack
1. Given two integer arrays, val and wt, each of size N, which represent the values and weights of N items respectively, and an integer W representing the maximum capacity of a knapsack, determine the maximum value achievable by selecting a subset of the items such that the total weight of the selected items does not exceed the knapsack capacity W.
   Each item can either be picked in its entirety or not picked at all (0-1 property). The goal is to maximize the sum of the values of the selected items while keeping the total weight within the knapsack's capacity.
   ```
   pick or notpick
   pick only when you have capacity
   ```
2. ##### Minimum coins
   Given an integer array of coins representing coins of different denominations and an integer amount representing a total amount of money. Return the fewest number of coins that are needed to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. There are infinite numbers of coins of each type
   ```
   pick or notpick
   pick only when the amount > coins[i]
   after picked stay at same position as we have infinity coins of each, but amount required will be reduced
   at base case if coins[0] divides amount return amount/coins[0] or else MAX_VALUE;

   at the end if we get max_val as answer then it is not possible to find ans return -1;
   ```
##### Coin change II - distinct ways
3. Give an array coins of n integers representing different coin denominations. Your task is to find the number of distinct combinations that sum up to a specified amount of money. If it's impossible to achieve the exact amount with any combination of coins, return 0. Single coin can be used any number of times. Return your answer with modulo 109+7.
   ```
   pick + notpick
   if we can't find answer at the end ( i<0 ) then return 0;
   if we find the answer at the end (arr[i] == amount ) return 1;
   ```
##### Unbounded knapsack
4. Given two integer arrays, val and wt, each of size N, representing the values and weights of N items respectively, and an integer W, representing the maximum capacity of a knapsack, determine the maximum value achievable by selecting a subset of the items such that the total weight of the selected items does not exceed the knapsack capacity W. The goal is to maximize the sum of the values of the selected items while keeping the total weight within the knapsack's capacity.
   An infinite supply of each item can be assumed.
   ```
   after pick stay at same position
   ```
##### Rod cutting problem
Given a rod of length N inches and an array price[] where price[i] denotes the value of a piece of rod of length i inches (1-based indexing). Determine the maximum value obtainable by cutting up the rod and selling the pieces. Make any number of cuts, or none at all, and sell the resulting pieces.
```
cut or not cut.
when a rod is cut at index i, pieceLen  = i+1
we can only cut when we have rod of enough size
if we want to cut a rod to piece of length i+1 we should have size >= len of piece


```

