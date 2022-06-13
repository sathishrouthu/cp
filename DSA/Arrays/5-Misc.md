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
