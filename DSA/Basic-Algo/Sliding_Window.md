# Sliding Window

The sliding window technique is useful for solving problems in arrays or strings. Generally, it is considered as a technique 
that could reduce the time complexity from O(n²) to O(n).

Sliding Window Technique is a method for finding subarrays in an array that satisfy given conditions.

We do this via maintaining a subset of items as our window and resize and move that window within the larger list until we find a solution.


There are two types of sliding window:

**Fixed window length k:**

the length of the window is fixed and it asks you to find something in the window such as the maximum sum of all windows, 
the maximum or a median number of each window. Usually, we need some kind of variables to maintain the state of the window, some are as simple 
as an integer or it could be as complicated as some advanced data structure such as list, queue, or deque.

**Two pointers + criteria:**

the window size is not fixed, usually it asks you to find the subarray that meets the criteria, 
for example, given an array of integers, find the number of subarrays whose sum is equal to a target value.


Let’s understand it by an example:

EXAMPLE: 
Given an array of positive integers, find a subarray that sums up to target. Let the array be [1, 2, 3, 4, 5, 6, 7, 8, 9] and target be 9.
We will start with window size = 1, then keep increasing the window size until the sum of elements inside the window is greater than or equal to the target.
If the sum equals to target return true else decrease the window size from the left and reduce the sum till it is less than or equal to the target.

![image](https://user-images.githubusercontent.com/93826731/174137451-edc0321f-3f15-442f-bebb-0c7376919c75.png)

```
 vector<int> subarraySum(int arr[], int n, long long s){
        
        int start = 0,i=1;
        long long cur_sum = arr[0];
        while(i<=n){
            while(cur_sum<s and i<=n){
                cur_sum+=arr[i];
                i++;
            }
            if(cur_sum==s)
               return {start+1,i};
            while(cur_sum>s){
                cur_sum -= arr[start];
                start++;
            }
            if(cur_sum==s)
               return {start+1,i};
        }
        return {-1};
     }

```


### Smallest Subarray With K Distinct Elements

Given an array 'A' consisting of 'N' integers, find the smallest subarray of 'A' containing exactly 'K' distinct integers.

If more than one such contiguous subarrays exist, consider the subarray having the smallest leftmost index.

EX :

IP  :  4 2 2 2 3 4 4 3 

OP  : 3 5

**BruteForce :**
```
- pick up each element as starting element
- initialize an empty set to keep distinct values
- for each starting elementnt find an ending such that the set size equals to k
   start inserting elements into set and check set size
   if set.size==k 
        update the start and end as 
         if(end-start < j-i )
           start = i
           end = j
        break from inner loop
   if j==n 
     break from outer loop
    
- if (end-start==n)
     return -1
- return {start,end};
```

```
#include<bits/stdc++.h>
vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k)
{
    int n= arr.size();
    int start=0,end=n,j;
    for(int i=0;i<n;i++){
        j=i;
        unordered_set<int> s;
        for(j=i;j<n;j++){
            s.insert(arr[j]);
            if(s.size()==k){
                if((j-i)<(end-start)){
                    start=i;
                    end=j;
                }
                break;
            }
        }
     if(j==n)
         break;
     if(flag==1 && i<start && j<end){
         start=i;
         end=j;
     }
    }
    if(start==0 && end==n) return {-1};
    return {start,end};

}



```


Sliding Window : 
 - we start from left and keep on expand window until we find the k distinct elements in window
 - when we find k distinct elements in window we shrink the window from left side inorder to find minimum length.
 - if we never find such window then our window size at the end will be equal to n (we exhausted)
 
 Ex : 
 ```
 given array : 1 1 3 2 1 4 5 1 1 3 3 
 
 we start with window size=0
 expand window : 
 
  no. of distinct elements |  window elements
            0              |       
            1              |       1
            1              |       1 1
            2              |       1 1 3
            3              |       1 1 3 2
            
here no of dist elements became 3 == k 
so we need to shrink the window from left 

  no. of distinct elements |  window elements
            3              |       1 1 3 2
            3              |       1 3 2
            
 with same no. of distinct elements we got a window of size 3 which is less than previous window size 4
 so we update the start , end now.
 in the same way we keep iterating over array until we exhaust the array.
```
```
- initialize a map that store element and its frequency
- two variables start=0 and end=n denotes the answer variables
- two variables i=0 and j=0 denoting the current size of window
- while(j<n) 
     increase the frequency of current element arr[j];
     while( map_size == k )
          -- check current window size (j-i) and update start and end;
          -- decrease the count of starting element of current window in map
          -- if count becomes 0 then remove that element from map
          -- i++ ( shrink the window from left )
     j++  ( expand window to the right )
     
- if(end-start == n) return {-1}   //No element found
- return {start,end};

```



```
#include<bits/stdc++.h>
vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k)
{
    int n = arr.size();
    int i=0,j=0,start=0,end=n;
    unordered_map<int,int> m;
    while(j<n){
            m[arr[j]]++;
            while(m.size()==k){
                if( (j-i) < (end-start)){
                    start=i;
                    end=j;
                }
                m[arr[i]]--;
                if(m[arr[i]]==0)
                    m.erase(arr[i]);
                i++;
            }
        j++;
    }
    if((end-start)==n)    return {-1};
    return {start,end};
}

```

### Three Pointer.

You are given three arrays X, Y and Z of size A,B and C respectively.Also, all three arrays are sorted in non-decreasing order.
Find i, j, k such that : 0 <= i < A, 0 <= j < B, 0 <= k < C and max(abs(X[i] - Y[j]), abs(Y[j] - Z[k]), abs(Z[k] - X[i])) is minimized.
Your task is to return the minimum of all the max(abs(X[i] - Y[j]), abs(Y[j] - Z[k]), abs(Z[k] - X[i]))

**Brute force approach :**

generate all posible triplets and find the :  minimum(maximum(abs(X[i]-[Y[j]),abs(Y[j]-Z[k]),abs(X[i]-Z[k]))

```
ans = INT_MAX;
max_dif=0;
for i --> 0 to A
   for j--> 0 to B
      for k-->0 to C
          max_diff = maximum(abs(X[i]-[Y[j]),abs(Y[j]-Z[k]),abs(X[i]-Z[k]);
          ans = min(diff,ans);      
return ans;
```

**Efficient way:**

* In this approach, we try to minimize the difference between the maximum and minimum extracted value at each index.
* We maintain three variable differences, minimum and maximum to store the current difference, minimum and maximum respectively for each index.
* We maintain 3 iterators, i,j,k pointing to the start of each array X, Y and Z respectively.
* Now, we find the values of differences, minimum and maximum for each i,j and k.
* If we found the difference at the current indices less than the previously stored difference, we update its value.
* Now, increment the pointer of the array which contains the minimum.
* We increment the pointer of the array which has the minimum because our goal is to decrease the difference.

```
start with three pointer i,j,k each pointig to X,Y,Z
for each iteration 
 - find the max of 3 elements at current
 - find the max of 3 elements at current
 - find diffrenece b/w max and min and update the results
 we have to minimize this difference to get optimal value of min difference of 3 elements
 inorder to minimize above value we have to increase the least valueamong 3 values.
 since the arrays are sorted we increase the pointer which has the least value among all 3;
 ```
 
 ```
 #include<bits/stdc++.h>
int maximum(int a, int b, int c)
{
   return max(max(a, b), c);
}
int minimum(int a, int b, int c)
{
   return min(min(a, b), c);
}
int threePointer(vector<int>& X, vector<int>& Y, vector<int>& Z)
{   
    int A = X.size();
    int B = Y.size();
    int C = Z.size();
    int Xi,Yi,Zi;
    int i=0,j=0,k=0,h,l;
    int diff = INT_MAX;
    int abs_max,ans = INT_MAX;
    while(i<A && j<B && k<C){
        h = maximum(X[i],Y[j],Z[k]);
        l = minimum(X[i],Y[j],Z[k]);
        if ( h-l < diff ){
            diff = h-l;
            abs_max = maximum(abs(X[i]-Y[j]),abs(Y[j]-Z[k]),abs(X[i]-Z[k]));
            ans = min(ans,abs_max);
        }
        if(l==X[i]){
            i++;
        }
        else if(l==Y[j])
            j++;
        else
            k++;
    }
    return ans;    
}
 
 ```



