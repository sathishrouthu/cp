## Kadane's Algo:
Given an array of N integers a1,a2,a3,....., aN find the maximum subarray(non-empty) sum of the given array.

Ex:
Array A[] = [-1, 2, -2, 5, 7, -3, 1]
Maximum subarray sum -> 12
Subarray(0-Based indexed) from index 1 to 4 -> [2, -2, 5, 7] and subarray(0-Based indexed) from index 3 to 4 -> [5, 7] have sum 12.

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
You are given an array of integers ARR[] of size N consisting of zeros and ones. You have to select a subset and flip bits of that subset. You have to return the count of maximum one’s that you can obtain by flipping chosen sub-array at most once.
A flip operation is one in which you turn 1 into 0 and 0 into 1.
Ex :
If you are given an array {1, 1, 0, 0, 1} then you will have to return the count of maximum one’s you can obtain by flipping anyone chosen sub-array at most once, so here you will clearly choose sub-array from the index 2 to 3 and then flip it's bits. So, the final array comes out to be {1, 1, 1, 1, 1} which contains five ones and so you will return 5.

my Approach:
1. count no. of ones in given array
2. in the given array change 0 to +1 and 1 to -1
3. now findout the maxsubarray sum in the array (kadane's algo)
4. return no.of ones + maxsubarray sum ( result of step1 + result of step 3).

```
int ones = 0;
for(int i=0;i<n;i++){
	if(arr[i]==1){
	    ones+=1;
	    arr[i]=-1;   
	}
	else
    		arr[i]=1;
    }
int curr_Sum = 0;
int maxSum = -1;
for(int i=0;i<n;i++){
	curr_Sum += arr[i];
	maxSum = max(curr_Sum,maxSum);
	curr_Sum=curr_Sum<0?0:curr_Sum;
	}
maxSum = maxSum>0?maxSum:0;
return (ones+maxSum);
    
```


Problem:
#### Maximum subarray sum after K concatenation
You have been given a vector/list 'ARR' consisting of ‘N’ integers. You are also given a positive integer ‘K’.
Let’s define a vector/list 'CONCAT' of size 'N * K' formed by concatenating 'ARR' ‘K’ times. For example, if 'ARR' = [0, -1, 2] and 'K' = 3, then 'CONCAT' is given by [0, -1, 2, 0, -1, 2, 0, -1, 2].
Your task is to find the maximum possible sum of any non-empty subarray (contagious) of 'CONCAT'.

Naive:
- We will loop from 0 to ‘N * K’ (loop variable ‘i’).
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
* If 'ARR_SUM' > 0
	Then, we will find the maximum subarray sum for K = 2 and we return ‘MAX_SUBARRAY_SUM’ plus (K-2) times ‘ARR_SUM' as the answer.
	
```
long long maxSubSumKConcat(vector<int> &arr, int n, int k)
{
    long long currsum=0,maxsum = -9999999;
    for(int i=0;i<n*2;i++){
            currsum+=arr[i%n];
            maxsum = max(maxsum,currsum);
            currsum = currsum<0?0:currsum;
        }
    long long sum=0;
    for(i : arr)	sum+=i;
    if(sum<=0)
        return maxsum;
    else
        return maxsum+sum*(k-2);
}

```
