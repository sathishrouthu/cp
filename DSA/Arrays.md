#### Kadane's Algo:
Given an array of N integers a1,a2,a3,....., aN find the maximum subarray(non-empty) sum of the given array.

Ex:
Array A[] = [-1, 2, -2, 5, 7, -3, 1]
Maximum subarray sum -> 12
Subarray(0-Based indexed) from index 1 to 4 -> [2, -2, 5, 7] and subarray(0-Based indexed) from index 3 to 4 -> [5, 7] have sum 12.

'''

	long long Curr_sum=0,maxSum=-99999999;
	for(int i=0;i<n;i++){
        Curr_sum = Curr_sum+arr[i];
        maxSum = max(maxSum,Curr_sum);
        Curr_sum = Curr_sum<0?0:Curr_sum;
	}
	return maxSum>0?maxSum:0;
  
'''
