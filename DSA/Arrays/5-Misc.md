### Pair Sum

You are given an integer array 'ARR' of size 'N' and an integer 'S'. 
Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.

- Each pair should be sorted i.e the first value should be less than or equals to the second value. 

- Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.

```
vector<vector<int>> pairSum(vector<int> &arr, int s){
    sort(arr.begin(),arr.end());
    vector<vector<int>> result;
    for(int i=0;i<arr.size();i++){
        int comp = s-arr[i];
        vector<int> pair(2);
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]==comp){
                pair[0] = arr[i]<arr[j]?arr[i]:arr[j];
                pair[1] = s-pair[0];
                result.push_back(pair);
            }
        }
    }
    return result;
}
```
### Valid Pairs
You are given an array 'ARR' of 'N' integers and two integers 'K' and 'M'.
You need to return true if the given array can be divided into pairs such that the sum of every pair gives remainder 'M' when divided by 'K'. Otherwise, you need to return false.

Ex: 
If the given array is [2, 1, 5, 7] and K = 9 and M = 3. Then you need to return true because we can divide the array into two pairs, i.e (2, 1) and (5, 7) whose sums are 3 and 12, which when divided by 9 gives remainder 3, thus it is possible to divide the given array into pairs.  

* Every element of the array should contribute to only one pair, i.e if the array is [3, 0, 0] and K = 2 and M = 1, then you need to return false, as element 3 will make a pair with any one of the 0. 

```
#include<bits/stdc++.h>

bool isValidPair(vector<int> &arr, int n, int k, int m)

{

   // Write your code here.

   if(n%2!=0)
       return false;
   unordered_map<int, int> ans;
   bool a=false;
   for(int i=0; i<n; i++)
       ans[arr[i]%k]++;
   for(int i=0; i<n; i++)
   {
       int r1=ans[arr[i]%k];
       int r2;
       if(arr[i]%k<=m)
           r2=ans[m-(arr[i]%k)];
       else
           r2=ans[(k-(arr[i]%k))+m];
       if(r1!=r2)
           return false;
   }
   return true;
}


```


### Best Time to Buy and Sell Stock  (Leetcode - 121)

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Input: prices = [7,1,5,3,6,4]

Output: 5

Solution

maintain a minimum value from left side as min_buy value and at each value in the array check for the profit you're getting 

if the profit is maximized by selling at current index , update the profit.


```

int maxProfit(vector<int>& prices) {
    int min_buy = INT_MAX;
    int profit=0;
    for(int i=0;i<prices.size();i++){
        min_buy = min(min_buy,prices[i]);
        profit  = max(profit,prices[i]-min_buy);
    }
    return profit;
}

```

FOLLOW UP :

 * Best Time to Buy and Sell Stock - II
 *  Best Time to Buy and Sell Stock - III

### Non-Decreasing Array
You have been given an integer array/list 'ARR' of size 'N'. Write a solution to check if it could become non-decreasing by modifying at most 1 element.

We define an array as non-decreasing, if ARR[i] <= ARR[i + 1] holds for every i (0-based) such that (0 <= i <= N - 2).

```
find the position where the modification is needed..!
this can be done by checking where this condition occurs arr[i]>arr[i+1] 
there are several cases need to be checked

1. if the mismatch position occurs more than once in the array return false;
2. if the position = 0 return true
3. if the position is in between 0 to n-2
    check the following conditions 
    ==> arr[pos-1] <= arr[pos+1]  
    Ex : [ 3,4,2,8 ]
    the mismatch position occured at i=1
        we have to check arr[pos-1]<=arr[pos+1] such that 3<2 then only we are able to modify the array to a non-decreasing array;
    
    ==> arr[pos]<=arr[pos+2]
    Ex : [ 3,4,2,8 ]
        to make the above array non decreasing we have to change the value at pos+1 to value in between 4 and 8
        so we have to check whether 4<=8 or not? ,  that means arr[pos]<=arr[pos+2] 
    
 4. And finally if mismatch position is occured at pos==n-2 ( at the end of the array) 
    we can cheange this last value to any max value so we can return true.
 
 ```
 ```
bool isPossible(int *arr, int n){
    int pos=-1;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            if(pos!=-1)    return false;    // this occurs when the error position occured twice
            pos=i;
        }
    }
    return pos==-1||pos==0||pos==n-2||arr[pos-1]<=arr[pos+1]||arr[pos]<=arr[pos+2];
}
 
 ```
