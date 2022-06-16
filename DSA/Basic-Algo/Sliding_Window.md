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
