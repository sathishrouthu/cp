### Maximum of all subarrays of size k

Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

```
Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6
```

```
vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> dq;
        vector<int> res;
        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front() == i-k)
                dq.pop_front();
            while(!dq.empty() && arr[i]>arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
                res.push_back(arr[dq.front()]);
        }
        return res;
    }

```
