## Prefix Sum:
  Given an array, ‘A’ of size N, its prefix sum array is an array of the same size N such that the ith element of the prefix sum array ‘Prefix’ is the sum of all elements of the given array till ith index from the beginning, i.e Prefix[i] = A[0] + A[1] + A[2] + … + A[i]. 
* Useful for answering efficiently range sum/xor queries, provided the array elements do not change over which the prefix sum/xor array is calculated.
* Product of elements in a given range.
* Useful for calculating maximum sum subarray and many more...

## Suffix Sum:
Given an array ‘A’ of size N, its suffix sum array is an array of the same size N such that the ith element of the suffix sum array ‘Suffix’ is the sum of all elements of the given array till ith index from the end, i.e Suffix[i] = A[i] + A[i+1] + A[i+2] + … + A[N-1] - (0-Based indexing).



### Sum Of Infinite Array:
Given an array “A” of N integers and you have also defined the new array “B” as a concatenation of array “A” for an infinite number of times.
For example, if the given array “A” is [1,2,3] then, infinite array “B” is [1,2,3,1,2,3,1,2,3,.......].
Now you are given Q queries, each query consists of two integers “L“ and “R”(1-based indexing). Your task is to find the sum of the subarray from index “L” to “R” (both inclusive) in the infinite array “B” for each query.

The value of the sum can be very large, return the answer as modulus 10^9+7.
1 <= T <= 100
1 <= N <= 10^4   
1 <= A[i] <= 10^9
1 <= Q <= 10^4
1 <= L <= R <= 10^18

Time Limit: 1sec


- Naive Approach: 
The simplest approach to solve the given problem is to iterate over the range [L, R] using the variable i and add the value of arr[i % N] to the sum for each index. After completing the iteration, print the value of the sum as the resultant sum.

The above approach can also be optimized by using the Prefix Sum. Follow the steps below to solve the problem:

- Initialize an array, say prefix[] of size (N + 1) with all elements as 0s.
- Traverse the array, arr[] using the variable i and update prefix[i] to sum of prefix[i – 1] and arr[i – 1].
- Now, the sum of elements over the range [L, R] is given by:

    **The sum of elements in the range [1, R] – sum of elements in the range [1, L – 1]**

1. Initialize a variable, say leftSum as ((L – 1)/N)*prefix[N] + prefix[(L – 1)%N] to store the sum of elements in the range [1, L-1].
2. Similarly, initialize another variable rightSum as (R/N)*prefix[N] + prefix[R%N] to store the sum of elements in the range [1, R].
3. After completing the above steps, print the value of (rightSum – leftSum) as the resultant sum of elements over the given range [L, R].


```

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    long long sum=0,ans=0,L,R;
    long long leftSum,rightSum;
    long long mod = 1000000007;
    vector<int> v;
    vector<long long> pre={0};
    for(int i=1;i<=n;i++){
        pre.push_back(pre[i-1]+arr[i-1]);
    }
    for(int i=0;i<q;i++){
        
        L = queries[i][0];
        R = queries[i][1];
        
        rightSum = (R/n)*pre[n]+pre[R%n];
        leftSum = ((L-1)/n)*pre[n]+pre[(L-1)%n];
        long long ans = rightSum-leftSum;
        ans%=mod;
        v.push_back(ans);
    }
    return v;
}

```

### Product of array except itself (238 Leetcode)

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

Naive Approach :
<pre>
Compute prefix product array : prefix[i] = arr[0]\*arr[1]\*arr[2]......arr[i];

compute suffix product array : suffix[i] = arr[n-1]\*arr[n-2]\*arr[n-3].....arr[i];

now the resultant array can be obtained by  : 
prod[0] = suffix[1];
prod[n-1] = prefix[n-2];
prod[i] = prefix[i-1] * suffix[i+1];  (i=1 --> n-2 );
</pre>

```
vector<int> productExceptSelf(vector<int>& nums) {
      int n=nums.size();
      vector<int> pre(n),suf(n),prod(n);
      
      pre[0] = nums[0];
      for(int i=1;i<n;i++){
          pre[i]=pre[i-1]*nums[i];
      }
      suf[n-1] = nums[n-1];
      for(int i=n-2;i>=0;i--){
          suf[i] = suf[i+1]*nums[i];
      }
      prod[0] = suf[1];
      prod[n-1] = pre[n-2];

      for(int i=1;i<nums.size()-1;i++){
          prod[i] = pre[i-1]*suf[i+1];
      }
      return prod;
  }

```

Efficient approach by using O(1) space:

First take an array product[]  :  final output array
```
initialize a variable temp = 1;
for each index i from 0 to n-1:
  prod[i] = temp;
  temp*=arr[i];
```

above loop will calculate the product[i] = product of all elements upto to i-1;

```
now again intitialize temp=1
for each index i from n-1 to 0:
  prod[i] = temp;
  temp*=arr[i];
```
  
above loop will calculate the required final output such that the product of all other elements except that number


```
vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> prod(n);
    int temp=1;
    for(int i=0;i<n;i++){
        prod[i] = temp;
        temp*=nums[i];            
    }
    temp=1;
    for(int i=n-1;i>=0;i--){
        prod[i]*=temp;      
        temp*=nums[i];
    }
    return prod;
}
```


### Count all sub-arrays having sum divisible by k

Given an array ‘ARR’ and an integer ‘K’, your task is to find all the count of all sub-arrays whose sum is divisible by the given integer ‘K’.

*If there exists no subarray in the given sequence whose sum is divisible by ‘K’ then simply return ‘0’.*

**Naive approach:**

obtain sum of all posible subarrays and check for divisibility of each sub array sum
```
for i from 0 to n-1:
  for j from i to n-1:
      currsum=0;
        for k=i to j;
          currsum+=arr[k];
      if(currsum%k==0)
        count++;
return count;

```

**Efficient way:**

for any subarray to be divided by k => subarraySum(i,j)%k==0;

subarraySum(i,j) = sum(0,j) - sum(0,i-1);

subarraySum(i,j) = (q1\*k + rem1) - (q2*\k+rem2); ==> (q1-q2)*k + (rem1-rem2)

so, finally if subarraysum(i,j) need to be divided by k then rem1==rem2

rem1 = (arr[0]+arr[1]+.......arr[i-1])%k

rem2 = (arr[0]+arr[1]+.......arr[j])%k

condition :  rem1==rem2

we need to find  no. of (i,j) pairs which satisfies above condition

--------------------------------------------------------------------

create an array say rem of size k;

rem[k];  this array holds count of each reminder we get for sum upto each index in arr

example : 

array = [2,3,-3,4,-6,1] , k = 3

cumulative sums = [2, 5, 2, 6, 0, 1]

initially mod[k] = [ 0, 0, 0 ]
```
for i--> 0 to n-1;
  reminder = (cumlativesum of arr upto i)%k;
  mod[reminder]++;
```
mod[k] = [2,1,3]

such that we got reminder 
0 : 2 times
1 : 1 time 
2 : 3 times

after computing mod array :
```
for each x in mod:
  if(x>1)
    count+= x*(x-1)/2;
count += mod[0]

```

x*(x-1)/2 ==> we are finding no. of pairs that can be formed by x no.of elements

count+=mod[0] we are also counting subarrays having reminder 0 (single elements can also be subarrays)

```
	long long subCount(long long arr[], int N, long long K)
	{
	    long long count=0;
	    long long cumSum=0;
	    int rem[K] = {0};
	    for(int i=0;i<N;i++){
	            cumSum+=arr[i];
	            rem[((cumSum%K)+K)%K]++;
              // we are taking mod twice because sum may be ngatve some times
	       }
	        for(int i=0;i<K;i++){
	            if(rem[i]>1)
	                count += (rem[i]*(rem[i]-1))/2;
	        }
	        count+=rem[0];
	    return count;
	}

```

