##### Longest Increasing Subsequence
1. Given an integer array nums, return the length of the longest strictly increasing subsequence.
   A subsequence is a sequence derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3, 6, 2, 7] is a subsequence of [0, 3, 1, 6, 2, 2, 7].
   The task is to find the length of the longest subsequence in which every element is greater than the previous one.
   ```
   using dp:
   f(i,prev)
     pick only when arr[i] > arr[prev]

   optimal using binary search:
   maintain a list of increasing subsequence.
   iterate over array, at each index
     if arr[i] > last inserted element in sequence:
       insert into list.
     else:
       replace the element at it's suitable position in the sequence ( lower bound (use binary search))
   the sequence will ensure the length of LIS but not the actual LIS.
   lower bound: find the index of least element which is greater than or equal given element.
   ```
##### Print Longest Increasing Subsequence
2. Given an array of n integers arr, return the Longest Increasing Subsequence (LIS) that is Index-wise Lexicographically Smallest
   The Longest Increasing Subsequence (LIS) is the longest subsequence where all elements are in strictly increasing order.\
   A subsequence A1 is Index-wise Lexicographically Smaller than another subsequence A2 if, at the first position where A1 and A2 differ, the element in A1 appears earlier in the array arr than corresponding element in S2.
   Your task is to return the LIS that is Index-wise Lexicographically Smallest from the given array.
   ```
   Use different tabulation method.
   dp[i] tells len of lis till index i; inititally filled with all 1s.
   prev[i] tells the prev element index to the arr[i] in the LIS. initially filled with i itself for each i.
   maintain lastIndex which tells the lastIndex with max value in LIS.
   for each index (i-> 0 to n-1)":
     iterate over all of it's prev elements in array: ( j-> 0 to i-1 )
       update dp[i] if arr[j] > arr[i] && 1+dp[j] > dp[i]:
         at the sametime keep track of j in prev[i] = j;
         update the lastIndex if len found is greater
   Now iterate over prev to get LIS.
   start from lastIndex and trace back in prev[] until the prev[lastIndex] != lastIndex
   ```
##### Largest Divisible Subset
3. Given an array nums of positive integers, the task is to find the largest subset such that every pair (a, b) of elements in the subset satisfies a % b == 0 or b % a == 0. Return the subset in sorted order. If there are multiple solutions, return any one of them.
   ```
   in LIS we check for increasability. ( nums[i] > nums[j] )
   here we check divisibility. ( nums[i]%nums[j] == 0 )
   if a divides b and b divides c the automatically a divides c. (a<b<c)
   Sort the array first.
   for each index check all of it's prev elements and check divisibility to include in sequence.
   if( arr[i]%arr[prev]==0 && 1+dp[prev] > dp[i]):
     update dp[i] and keep track of prev in a trace array.
   ```
##### Longest String Chain
4. Given an array of strings words[], the task is to return the longest string chain. A string chain is defined as a sequence of words where,
   Each word (except the first) can be formed by inserting exactly one character into the previous word.
   The first word of the chain can be any word from the words[] array.
   The task is to determine the length of the longest chain.
   ```
   sort the words by their length.
   check words[i] and words[prev] has only one character difference

   checking:
     1. w1.length should be equal to w2.length-1;
     2. iterate over each char: ( i->w1 , j->w2 )
       if both matches move to next in both words ( i++, j++ )
       else: move next only in w2 (j++)
     at the end, we should end up the pointer at length of w1 and w2 ( i==w1length and j==w2.length ) then return true other wise false;
   
   ```
##### Longest Bitonic Subsequence
5. Given an array arr of n integers, the task is to find the length of the longest bitonic sequence.
   A sequence is considered bitonic if it first increases, then decreases. The sequence does not have to be contiguous.
   ```
   find the increasing subsequence from forward direction of the array and populate the dp in forward[]
   find the increasing subsequence from backward direction of the array and populate the dp in backward[]
   forward[i] tells lis till index i in --> direction.
   backward[i] tells the lis till index i in <-- direction ( i.e longest decreasing sequence in --> from index i )
   ans = max(forward[i] + backward[i] -1 ) for i -> 0 to n-1
   ```
##### Number of Longest Increasing Subsequences
6. Given an integer array nums, find the number of Longest Increasing Subsequences (LIS) in the array.
   ```
   keep track of count in a count[] array. initially filled with 1s.
   while finding lis:
     if a greater len of lis found: ( i.e: 1+dp[prev] > dp[i] )
       reset the count[i] = count[prev] ( as we can form count[prev] subsequences by including arr[i] in the prev subsequence
     else if same len of lis found ( i.e: 1+dp[i] == dp[i] )
       add the prev count to curr count ( we had count[prev] sequences with len dp[i] earlier, if we add arr[i] to those sequences we will get count[prev] more sequences, so we add count[prev] to the count[i] )

   for example:
         say arr = [1,5,4,3,6,7,10]
         dp[]    = [1,2,2,2,_,_,_]
         count   = [1,1,1,1,_,_,_]
       now we are at i=4 arr[i]=6
         - prev = 1, arr[prev] = 5, 1+arr[prev]>dp[i] therefore we set dp[i] = 1+dp[prev] and count[i] = count[prev] which is 1;
         dp      = [1,2,2,2,3,_,_]
         count   = [1,1,1,1,1,_,_]
         - prev = 2, arr[prev] = 4, 1+dp[prev] == dp[i] now we observer that we already have this len encountered before.
         the possible subsequence of same len are:
           1,4,6 ( new sequence )
         we had count[prev] ( 1 in this case ) sequences with len 2 earlier,
         if we add curr element to those sequences we will get count[prev] more sequences of len dp[i]
         count[i] += count[prev]
         count   = [1,1,1,1,2,_,_]
         - prev = 3, arr[prev] = 3 , 1+dp[prev] == dp[i]
         count   = [1,1,1,1,3,_,_]
   ```


















   
