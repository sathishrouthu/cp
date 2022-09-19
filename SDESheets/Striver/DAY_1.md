### Set Matrix Zero
**Problem Statement:**  Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

```
vector<vector<int>> findGoodMatrix(vector<vector<int>> &arr) 
{
    int r = arr.size();
    int c = arr[0].size();
    int col0=0;
    for(int i=0;i<r;i++){
        if(arr[i][0]==0)
            col0=1;
        for(int j=1;j<c;j++){
            if(arr[i][j]==0){
                arr[i][0]=0;
                arr[0][j]=0;
            }
        }
    }
    for(int i=r-1;i>=0;i--){
        for(int j=c-1;j>0;j--){
            if(arr[i][0]==0 || arr[0][j]==0){
                arr[i][j]=0;
            }
        }
        if(col0==1){
           arr[i][0]=0;
        }
    }
    return arr;
}

```

### Pascal’s Triangle

 Given an integer N, return the first N rows of Pascal’s triangle.

In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown in the figure below

```
Input Format: N = 5

Result:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

Explanation: There are 5 rows in the output matrix. Each row corresponds to each one of the rows in the image shown above.

```

<a href="https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/"> solution here </a>

```
#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> res(n);
    for(int i=0;i<n;i++){
        res[i].resize(i+1);
        res[i][0] = 1;
        res[i][i] = 1;
        for(int j=1;j<i;j++){
            res[i][j]=res[i-1][j-1]+res[i-1][j];
        }
    }
    return res;
}
```


### Next_Permutation

next_permutation : find next lexicographically greater permutation
Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

```
Input format: Arr[] = {1,3,2}

Output: Arr[] = {2,1,3}

Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.

```


```
void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
    
```

### Kadane's Algo 

Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and return its sum and print the subarray.
```
Input: arr = [-2,1,-3,4,-1,2,1,-5,4] 

Output: 6 

Explanation: [4,-1,2,1] has the largest sum = 6. 

```
```
    int maxSubArray(vector<int>& nums) {
        int cur_sum = 0;
        int max_sum = nums[0];
        for(int i=0;i<nums.size();i++){
            cur_sum += nums[i];
            max_sum = max(cur_sum,max_sum);
            cur_sum = cur_sum<=0?0:cur_sum;
        }
        return max_sum;
    }

```



### Sort an array of 0s, 1s and 2s  (Dutch National Flag)

**Three-way partitioning : **

Maintain three indices low = 0, mid = 0, and high = N-1, where N is the number of elements in the array.
* The range from 0 to low denotes the range containing 0s.
* The range from low to mid denotes the range containing 1s.
* The range from mid to high denotes the range containing any of 0s, 1s, or 2s.
* The range from high to N-1 denotes the range containing 2s.

The mid pointer denotes the current element, traverses the array while mid<=high i.e we have exhausted the search space for the range which can contain any of 0s, 1s, or 2s.

* If A[mid] == 0, swap A[mid] and A[low] and increment low and mid pointers by 1.
* If A[mid] == 1, increment the mid pointer by 1.
* If A[mid] == 2, swap A[high] and A[mid] , decrement high by 1.
* The resulting array will be a sorted array containing 0s, 1s, and 2s.


```

void sort012(int *arr, int n)
{
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
            mid++;
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

```


### Buy and Sell Stocks.

Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

```
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and 
sell on day 5 (price = 6), profit = 6-1 = 5.

Note: That buying on day 2 and selling on day 1 
is not allowed because you must buy before 
you sell.

```

```
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int minPrice = 99999999999;
    int maxProfit = 0;
    for(int i=0;i<n;i++){
        minPrice = min(minPrice,prices[i]);
        maxProfit = max(maxProfit,prices[i]-minPrice);
    }
    return maxProfit;
}

```
