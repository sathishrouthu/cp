##### Best time to buy and sell stock
1. Given an array arr of n integers, where arr[i] represents price of the stock on the ith day. Determine the maximum profit achievable by buying and selling the stock at most once.
   The stock should be purchased before selling it, and both actions cannot occur on the same day.
   ```
   maintain a leftMin value
   ```
##### Best time to buy and sell stock II - any no.of transactions
2. Given an array arr of n integers, where arr[i] represents price of the stock on the ith day. Determine the maximum profit achievable by buying and selling the stock any number of times.
   Holding at most one share of the stock at any given time is allowed, meaning buying and selling the stock can be done any number of times, but the stock must be sold before buying it again. Buying and selling the stock on the same day is permitted.
   ```
   add a parameter to determine whether we hold stock or not.
   buy only when we don't hold stock and sell only when we hold stock
   add negative stock value to profit while buying. =>  -arr[i] + f(i+1, true)
   add positive stock value to profit while selling. => arr[i] + f(i+1,false)
   return max of above transactions
   ```
##### Best time to buy and sell stock III - at most 2 transactions
3. Given an array, arr, of n integers, where arr[i] represents the price of the stock on an ith day, determine the maximum profit achievable by completing at most two transactions in total.
   Holding at most one share of the stock at any time is allowed, meaning buying and selling the stock twice is permitted, but the stock must be sold before buying it again. Buying and selling the stock on the same day is allowed.
   ```
   add a parameter trans which tells no. of transactions available to do.
   add a base case: when trans==0 we can't get any more profit further so return 0;
   buy only when we don't hold stock and sell only when we hold stock
   while selling the stock decrease the trans by 1

   start with trans=2
   ```
##### Best time to buy and sell stock IV - at most K transactions
4. Given an array, arr, of n integers, where arr[i] represents the price of the stock on an ith day, determine the maximum profit achievable by completing at most k transactions in total. Holding at most one share of the stock at any given time is allowed, meaning buying and selling the stock k times is permitted, but the stock must be sold before buying it again. Buying and selling the stock on the same day is allowed.
   ```
   start with trans=k
   ```
##### Best time to buy and sell stock V - with trans fee
5. Given an array arr where arr[i] represents the price of a given stock on the ith day. Additionally, you are given an integer fee representing a transaction fee for each trade. The task is to determine the maximum profit you can achieve such that you need to pay a transaction fee for each buy and sell transaction. The Transaction Fee is applied when you sell a stock.
   You may complete as many transactions. You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before buying again).
   ```
   while selling a stock, reduce the fee from profit

   sell = -fee + arr[i]+ f ( i+1, false )
   ```

   
