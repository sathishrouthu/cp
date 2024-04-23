## Kadane's Algo:

```
Given an array of N integers a1,a2,a3,....., aN find the maximum subarray(non-empty) sum of the given array.

Ex:
Array A[] = [-1, 2, -2, 5, 7, -3, 1]
Maximum subarray sum -> 12
Subarray(0-Based indexed) from index 1 to 4 -> [2, -2, 5, 7] and subarray(0-Based indexed) from index 3 to 4 -> [5, 7] have sum 12.
```

```

	long long Curr_sum=0,maxSum=-99999999;
	for(int i=0;i<n;i++){
        Curr_sum = Curr_sum+arr[i];
        maxSum = max(maxSum,Curr_sum);
        Curr_sum = Curr_sum<0?0:Curr_sum;
	}
	return maxSum>0?maxSum:0;

```

Problem:

#### Flip Bits

You are given an array of integers ARR[] of size N consisting of zeros and ones. You have to select a subset and flip bits of that subset. You have to return the count of the maximum one’s that you can obtain by flipping chosen sub-array at most once.
A flip operation is one in which you turn 1 into 0 and 0 into 1.
Ex :
If you are given an array {1, 1, 0, 0, 1} then you will have to return the count of maximum one’s you can obtain by flipping anyone chosen sub-array at most once, so here you will clearly choose a sub-array from the index 2 to 3 and then flip its bits. So, the final array comes out to be {1, 1, 1, 1, 1} which contains five ones and so you will return 5.

Intuition :
when we choose a subarray and flip it, for the zeros we gain +1 and for ones we lose -1 ( the count of 1 bits );
in the chosen sub array the value of (no. of zeros - no. of ones) should be max;
such that if we find a sub-array that has more no. of ones than no. of zeros then we can flip that sub-array;
to get such a sub-array, we need to consider 0 as +1 and 1 as -1 then we can simply find the max sum sub-array ( which has more no. of 0s than the no. of 1s )

from the above step, we will get max no. of ones we can get max sum sub-array which is nothing but max no. of ones that we can get by flipping a sub array.
but the solution is to find the max number of ones in the array at end. we just add the max sum to the initial no. of ones existed in the array.

my Approach:

1. count no. of ones in the given array
2. in the given array change 0 to +1 and 1 to -1
3. now find out the max subarray sum in the array (kadane's algo)
4. return no.of ones + maxsubarray sum ( result of step1 + result of step 3).

```
public static int flipBits(int[] arr,int n) {
	int countOne = 0;
	int currSum = 0;
	int maxSum =0;
	for(int i =0;i<n; i++){
		countOne+=arr[i];
		int temp = arr[i]==0 ? 1:-1;
		currSum += temp;
		maxSum = Math.max(currSum,maxSum);
		currSum = Math.max(0,currSum);
	}
	return countOne+maxSum;
}
```

Problem:

#### Maximum subarray sum after K concatenation

```
You have been given a vector/list 'ARR' consisting of ‘N’ integers. You are also given a positive integer ‘K’.
Let’s define a vector/list 'CONCAT' of size 'N * K' formed by concatenating 'ARR' ‘K’ times.
For example, if 'ARR' = [0, -1, 2] and 'K' = 3, then 'CONCAT' is given by [0, -1, 2, 0, -1, 2, 0, -1, 2].
Your task is to find the maximum possible sum of any non-empty subarray (contagious) of 'CONCAT'.
```

Naive:

- We will loop from 0 to ‘N \* K’ (loop variable ‘i’).
- We initialize ‘CUR_SUM’ (to store sum of prefix elements) to 0 and ‘MAX_SUM’ (to store maximum subarray sum) to the minimum possible value.
- For each iteration, we will-
- Add ‘ARR[i % N]’ to ‘CUR_SUM’’.
- Update ‘MAX_SUM’ if it’s value is less than ‘CUR_SUM’’.
- If ‘CUR_SUM’’ becomes negative, we will reset it to 0.
- Finally, we return ‘MAX_SUM’ as our answer.

Optimal:

- If K = 1-
  We simply apply Kadane’s algorithm and return the maximum sum.
- Else,
  we find the sum of elements (‘ARR_SUM'). Now there are two cases-

* If 'ARR_SUM' <= 0
  Then, we will find the maximum subarray sum for ‘K’ = 2 irrespective of value of ‘K’ and return it as answer.

this is because if the total sum is negative then it will always reduce the max sum for example :
take arr = [ -2,0,-8,9 ] in this array, total sum = -1;
if we concatenate this any no. of times, we will get the same result as max sum for k=2;
for k = 2 : [ -2 0 -8 9 -2 0 -8 9 ]

- If 'ARR_SUM' > 0
  Then, we will find the maximum subarray sum for K = 2 and we return ‘MAX_SUBARRAY_SUM’ plus (K-2) times ‘ARR_SUM' as the answer.

if arr sum > 0 then we can multiply it k-2 times as it will increase the max sub-array sum.

```
public static long maxSubSumKConcat(ArrayList<Integer> arr, int n, int k) {
	long currSum = 0;
	long maxSum = arr.get(0);
	long totalSum = 0;
	for(int i = 0;i<n*2;i++){
		currSum += arr.get(i%n);
		maxSum = Math.max(maxSum, currSum);
		currSum = Math.max(currSum, 0);
		totalSum += arr.get(i%n);
	}
	totalSum /= 2;
	if(totalSum>0)
		return maxSum+(k-2)*totalSum;
	else return maxSum;
}

```

### Max Sum Rectangle

Problem :

You are given a matrix 'ARR' with 'N' rows and 'M' columns. Your task is to find the maximum sum rectangle in the matrix. Maximum sum rectangle is a rectangle with the maximum value for the sum of integers present within its boundary, considering all the rectangles that can be formed from the elements of that matrix.

ex :

```
1  2 -1 -4 -20

-8 -3  4  2  1

3  8  10  1  3

-4 -1  1  7  6
```

the rectangle (1,1) to (3,3) has maxSum of 29.

Solution :

Kadane’s algorithm for 1D array can be used to reduce the time complexity to O(n^3). The idea is to fix the left and right columns one by one and find the maximum sum contiguous rows for every left and right column pair. We basically find top and bottom row numbers (which have maximum sum) for every fixed left and right column pair. To find the top and bottom row numbers, calculate the sum of elements in every row from left to right and store these sums in an array say temp[]. So temp[i] indicates sum of elements from left to right in row i. If we apply Kadane’s 1D algorithm on temp[], and get the maximum sum subarray of temp, this maximum sum would be the maximum possible sum with left and right as boundary columns. To get the overall maximum sum, we compare this sum with the maximum sum so far.

```
public static int maxSumRectangle(int[][] arr, int row, int col){
	int finalMaxSum = arr[0][0];
	for(int left = 0;left<col;left++){
	    int temp[] = new int[row];
	    for(int right=left;right<col;right++){
		for(int i=0;i<row;i++) 
		    temp[i] += arr[i][right]; 
	
		// Apply kadane's on temp
		int currSum = 0;
		int maxSum = temp[0];
		for(int x=0;x<row;x++){
		    currSum += temp[x];
		    maxSum = Math.max(currSum,maxSum);
		    currSum = Math.max(currSum, 0);
		}
	
		finalMaxSum = Math.max(finalMaxSum, maxSum);
	    }
	}
	return finalMaxSum;
}
```
