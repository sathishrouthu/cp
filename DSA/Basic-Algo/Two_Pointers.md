### 167. Two Sum II - Input Array Is Sorted
```
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int i = 0;
        int j = nums.length-1;
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum==target){
                int[] ans = {i+1,j+1};
                return ans;
            }
            if(sum<target)
                i++;
            else
                j--;
        }
        return new int[0];
    }
}
```

### 15. 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.  
Notice that the solution set must not contain duplicate triplets.  
```
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;
        for(int i=0;i<n;i++){
            int j = i+1,k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    result.add(Arrays.asList(nums[i],nums[j],nums[k]));
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    while(i<n-1 && nums[i]==nums[i+1]) i++;
                    j++;
                    k--;
                }
                else if(sum<0)
                    j++;
                else
                    k--;
            }
        }
        return result;
    }
}
```

### 18. 4Sum
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:  

0 <= a, b, c, d < n  
a, b, c, and d are distinct.  
nums[a] + nums[b] + nums[c] + nums[d] == target  
You may return the answer in any order.  
  
```
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k = j+1,l=n-1;
                while(k<l){
                    long sum = nums[i]+nums[j];
                    sum += nums[k]+nums[l];
                    if(sum == target){
                        result.add(Arrays.asList(nums[i],nums[j],nums[k],nums[l]));
                        while(k<l && nums[k]==nums[k+1]) k++;
                        while(k<l && nums[l]==nums[l-1]) l--;
                        while(j<n-1 && nums[j]==nums[j+1]) j++;
                        while(i<n-1 && nums[i]==nums[i+1]) i++;
                        k++;
                        l--;
                    }
                    else if(sum<target)
                        k++;
                    else
                        l--;
                }
            }
        }
        return result;
    }
}
```

### 1498. Number of Subsequences That Satisfy the Given Sum Condition

You are given an array of integers nums and an integer target.  
Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 10^9 + 7.  

Ex : 
Input: nums = [3,5,6,7], target = 9  
Output: 4  
Explanation: There are 4 subsequences that satisfy the condition.  
[3] -> Min value + max value <= target (3 + 3 <= 9)  
[3,5] -> (3 + 5 <= 9)  
[3,5,6] -> (3 + 6 <= 9)  
[3,6] -> (3 + 6 <= 9)  

#### Naive Approach
In the given array, we need to find all subsequences first and then max Elemement and min element of each subsequence.
count all the subsequences which satisfies the condition.

#### Two pointers approach :  
if we generate a subsequence, it should follow the same order of elements as original array.
but after finding subsequence, whatever the order of elements we are just finding the minimum and maximum elements in that subsequence.  
that means, we are ignoring order of subsequence as we need only min and max elements which can present anywhere in the subsequence.  
for example: for the subsequence :  
[3,4,2,1] min and max elements are : 1,4  
these are same for the subsequence [ 1,2,3,4 ] also  
so, order of subsequence doesn't matter for the given codition in the question.  

now we sort the Array,  
for each element we take this element as minimum of subsequence and then we will the range in which max element can exist.  

for example [ 3,4,5,8 ] target = 9  
lets say i th element as minimum, if i=0 then minimum=3;  
then we will find maximum for our valid subsequence ie; 3 + max <= 9  
let's say this max as jth element. j = 2, max = 5  

there exists j-i+1 elements within range of min and max,  
now we can form 2^(j-i) subsequences with these elements, how ?  
we took 3 as minimum, and since our subsequence has to be non empty we will fix this element in all subsequences:
```
3	5	6
__________________
3	-	-	[3]
3	5	-	[3,5]
3	-	6	[3,6]
3	5	6	[3,5,6]
```
when we fix our current element, we have j-i elements to either pick or not pick each element, so we have 2^(j-i) options to create a subsequence.  
Algo : 
```
initializie i=0,j=n-1;
count = 0;
while i <= j:	
	if arr[i]+arr[j] < target:		// arr[i] is minimum and arr[j[ is maximum
 		count += pow(2,j-i);
   		i++;
   	else:					// our min and max sum > target
    		j--;
```
we need to calculate the Power function efficiently as we are calulating 2^j-i everytime.  
methods to calculate pow(x,n):  
1. Binary exponentiation  
2. pre calculate by using array and << operator.  
	pow[i] = pow[i-1]<<1 or pow[i-1]*2;  
```
class Solution {
    public int numSubseq(int[] nums, int target) {
        int mod = (int)1e9+7;
        Arrays.sort(nums);
        int n = nums.length;
        int[] pow = new int[n];
        pow[0] = 1;
        for(int i=1;i<n;i++)
            pow[i] = (pow[i-1]<<1)%mod;
        int i=0,j=n-1;
        int count = 0;
        while(i<=j){
            if(nums[i]+nums[j] <= target){
                count = (count+pow[j-i])%mod;
                i++;
            }else{
                j--;
            }
        }
        return count;
    }
}
```

### Longest Mountain Sub Array

You are given an array of 'N' integers denoting the heights of the mountains. You need to find the length of the longest subarray which has the shape of a mountain.

A mountain subarray is defined as a subarray which consists of elements that are initially in ascending order until a peak element is reached and beyond the peak element all other elements of the subarray are in decreasing order.

If the given array is: [1 3 1 4]. The longest mountain subarray would be 3. This is because the longest mountain is  [1 3 1] having length 3.

```
We need to findout the subarray sequence which has an 
an increasing sequence and then , a decreasing sequence.

--> so we trraverse the array from left to right
--> then we find if there is an increasing sequence and then the length of this.
--> after this we will find a decreasing sequence and its length is added to previous length.
--> finally we maintain a final answer which will be updated based length we find out in previous steps.

More clearly:

for i--> 1 to n-1:
    initialize count=1;
    j = i;
    // find increasing sequence length
    
    // find decreasing sequence length (if Exists )
    
    // update answer with count ( if needed )
    
    change i value to next beginning of mountain by i = j;
    
```

```
int longestMountain(int *arr, int n)
{
    int ans=0;
    int i,j;
    int count=0,flag;
    if(n<3) return 0;
    for(i=1;i<n;i++){
        //Find increasing sequence
        j=i;
        flag=0;
        count=1;
        while(j<n && arr[j]>arr[j-1]){
                count++;
                j++;
        }
            
        //find decreasing sequence
        
        if(j!=i){                               // here we are checking whether there is an increasing sequence or not find the decreasing sequence
            while(j<n && arr[j]<arr[j-1]){
                count++;
                j++;    
                flag=1;
            }

            //Find max length
            if(flag){                           // flag will describe whether there is a decreasing sequence or not?
                ans = max(ans,count); 
                j--;                            // keeping the j value to last value of decreasing sequence.
            }
        }
        i=j;                                    // jumping i to next beginning of the mountain
    }
    return ans;
}

```


### Find All Triplets With Zero Sum

You are given an array Arr consisting of n integers, you need to find all the distinct triplets present in the array which adds up to zero.
An array is said to have a triplet {arr[i], arr[j], arr[k]} with 0 sum if there exists three indices i, j and k such that i!=j, j!=k and i!=k and arr[i] + arr[j] + arr[k] = 0.

```
1. You can return the list of values in any order. For example, if a valid triplet is {1, 2, -3}, then (2, -3, 1), (-3, 2, 1) etc is also valid triplet. 
   Also, the ordering of different triplets can be random i.e if there are more than one valid triplets, you can return them in any order.
2. The elements in the array need not be distinct.
3. If no such triplet is present in the array, then return an empty list, and the output printed for such a test case will be "-1".

```
**Brute force approach:**

 Find all the triplets by using 3 for loops and if sum is equal to 0 then add them to the final answer and return;
  
  
**Two pointer technique**
```
> Sort the array

> For every element in the array :
    -- assume the current element as target ; target = arr[i];
    -- find the pair with sum == (-target) in the remaining sorted array which starts from i+1 to n-1;
    -- we can find this pair by using two pointer technique ( similar to two sum problem )
```
```
Algorithm:

1. Sort the array
2. for i --> 0 to n-1 
    l = i+1;
    r = n-1;
    while(l<r)
        if((arr[i]+arr[l]+arr[r])==0)
            add (arr[i],arr[l],arr[r])  to final answer;
        // We need to remove duplicate triplets so we do the following
        increment l while arr[l] == arr[l+1]
        decrement r while arr[r] == arr[r-1]
        increment i while arr[i] == arr[i+1]
        
        i++;
        r--;
3. return final answer; 
        
```


```
vector<vector<int>> findTriplets(vector<int>arr, int n) {
    sort(arr.begin(),arr.end());
    vector<vector<int>> res;
    int l,r;
    for(int i=0;i<n;i++){
        l = i+1,r=n-1;
        while(l<r){
            if((arr[i]+arr[l]+arr[r])==0){
                res.push_back({arr[i],arr[l],arr[r]});
                
                //To eliminate the duplicte triplets do the following 
                
                while(l<r and arr[l]==arr[l+1])
                    l++;
                while(l<r and arr[r]==arr[r-1])
                    r--;
                while(arr[i]==arr[i+1])
                    i++;
                
                l++;
                r--;
            }
            else if((arr[l]+arr[r])+arr[i]>0)
                r--;
            else
                l++;
        }
    }
    return res;
}

// Java Code

import java.util.* ;
import java.io.*; 
import java.util.ArrayList;

public class Solution {

    public static ArrayList<ArrayList<Integer>> findTriplets(ArrayList<Integer> arr, int n) {
        Collections.sort(arr);
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        for(int i = 0;i<n;i++){
            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = arr.get(i)+arr.get(l)+arr.get(r);
                if( sum == 0){
                    result.add(new ArrayList<>(Arrays.asList(arr.get(i),arr.get(l),arr.get(r))));
                    l++;
                    r--;
                    while(l<r && arr.get(l).equals(arr.get(l-1))) l++;
                    while(l<r && arr.get(r).equals(arr.get(r+1))) r--;
                }
                else if ( sum > 0)
                    r--;
                else 
                    l++;
                while(i+1<n && arr.get(i).equals(arr.get(i+1)))
                    i++;
            }
        }
         return result;
    }
}
```


### Container With Most Water

Given a sequence of ‘N’ space-separated non-negative integers A[1],A[2],A[3],......A[i]…...A[n]. Where each number of the sequence represents the height of the line drawn at point 'i'. Hence on the cartesian plane, each line is drawn from coordinate ('i',0) to coordinate ('i', 'A[i]'), here ‘i’ ranges from 1 to ‘N’. Find two lines, which, together with the x-axis forms a container, such that the container contains the most area of water.

Note

1. You can not slant the container i.e. the height of the water is equal to the minimum height of the two lines which define the container.

2. Do not print anything, you just need to return the area of the container with maximum water.

Ex: 

ip : 4 3 2 1 4
op : 16

ip : 1 2 1
op : 2

**Naive Approach**

find all the possible pairs and find max  area among all areas calculated
```
maxarea=0;
for i --> 0 to n-1:
    for j-->i+1 to n-1:
        area = (j-i)*min(arr[i]*arr[j]);
        maxarea= max(area,maxarea);
return maxarea;
        
```

**Two pointer technique**

We need to find a pair of heights that gives maximum area with x axis

the width on x-axis decreases or increase by constant value : 1

we need to find optimal height by two pointers

- first pointer points to 1st element;
- last pointer points to last element;
- we use these two pinter to know the best height that gives max area along with x axis;


![ezgif com-gif-maker3](https://user-images.githubusercontent.com/93826731/173886671-7346d153-a73e-4e1e-8537-be266cdb9fec.gif)


```
while first<last:
    if arr[first] < arr[last]
        first++;
    else
        last--;
```

```
int maxArea(vector<int>& height) {
    // Write your code here.
    int n= height.size();
    int l=0,h=n-1;
    int area= 0,x;
    while(l<h){
            x=(h-l)*min(height[l],height[h]);
                area = max(x,area);
            if(height[h]<height[l])
                h--;
            else
                l++;
        }
    return area;
}

```

### Trapping Rainwater

42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

![image](https://user-images.githubusercontent.com/93826731/193379772-476a4438-78da-4af8-9765-42bed69ab953.png)

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
```

**Brute force :**
```
At each index we need to findout how much water we can store after rain.
for example if we have an array like  : 

1  2  1  3  0  4  2

at index 0 : 0 units of water
at index 1 : 0 units of water
at index 2 : 1 unit of water 
at index 3 : 0 units
at index 4 : 3 units
at index 5 : 0 units 
at index 6 : 0 units

formula is simple :  
at each index we need to have two values leftmax value and right max value
units of water that can be trapped at index i : Min (leftmax,rightmax) - height[i];

Approach 2 : 
compute prefix and suffix array that tells the leftmax and right max :
for  an array like : [ 1  2  1  3  0  4  2 ]
prefix = [ 1, 2, 2, 3, 3, 4, 4 ]
suffix = [ 4, 4, 4, 4, 4, 4, 2 ]
at  index i :
leftmax  = prefix[i]
rightmax = suffix[i]
```
```
public static long getTrappedWater(long []arr, int n) {
    if(n<3) return 0;
    long[] leftMax = new long[n];
    long[] rightMax= new long[n];
    rightMax[n-2] = arr[n-1];
    for(int i=1;i<n-1;i++){
        leftMax[i] = Math.max(leftMax[i-1],arr[i-1]);
        rightMax[n-1-i] = Math.max(rightMax[n-i],arr[n-i] );
    }
    long result = 0;
    for(int i=1;i<n-1;i++){
        long trap =  (Math.min(leftMax[i],rightMax[i]) - arr[i]);
        result += trap>0 ? trap : 0;
    }
    return result;
}
```
```
Optimal Approach :

Using two pointers : 

1. initialize following :
    leftmax = rightmax = 0;
    l=0, r = n-1;
    result = 0;
2. while l<r :
    if height[l] <= height[r]               // that means for sure we have a rightmax to the index l 
        if(leftmax <= height[l]             // but we do not have a leftmax for index l
            leftmax = height[l];
        else                                // we have leftmax also
            res += leftmax - height[l];
        l++;
    else                                    // we do not have a right max for index l but we have a leftmax for index r
        if(rightmax<height[r] )             // we do not have a rightmax for index r
            rightmax = height[r];
        else                                //we have rightmax also.
            res+=rightmax-height[r];
        r--;
            

3. return res;

```

```
int trap(vector<int>& height) {
    int leftmax=0,rightmax=0,l=0,r=height.size()-1;
    int res=0;

    while(l<r){
        if(height[l]<=height[r]){
            if(height[l]>=leftmax)
                leftmax = height[l];
            else
                res+=leftmax-height[l];
            l++;
        }
        else{
            if(height[r]>=rightmax)
                rightmax = height[r];
            else
                res+=rightmax-height[r];
            r--;
        }
    }
    return res;
}

// Java Code

public static long getTrappedWater(long []arr, int n) {
        if(n<3) return 0;
        long leftMax = 0;
        long rightMax = 0;
        int l = 0;
        int r = n-1;
        long result = 0;
        while(l<r){
            if(arr[l]<=arr[r]){
                if(arr[l]<leftMax)
                    result+= leftMax - arr[l];
                else
                    leftMax = arr[l];
                l++;
            }
            else{
                if(arr[r]<rightMax)
                    result += rightMax - arr[r];
                else
                    rightMax = arr[r];
                r--;
            }
        }
         return result;
    }
```

### Sum of Two Elements Equals the Third.

You are given an array Arr consisting of n integers, you need to find a valid triplet as explained below.
An array is said to have a valid triplet {arr[i], arr[j], arr[k]} if there exists three indices i, j and k such that i != j, j != k and i != j and arr[i] + arr[j] = arr[k] or arr[i] + arr[k] = arr[j] or arr[k] + arr[j] = arr[i].

Arr can have duplicates

Arr = 10, 5, 5, 6, 2 

In this array, the triplet {10, 5, 5} is valid triplet because, 5 + 5 = 10.

similar to previous problems such that 

1. sort the array
2. fix the last element as target and find pairs in remaining array which sums upto target.
3. do this fro all elements as targets traversing from end of the array

```
vector<int> findTriplets(vector<int> &arr, int n) 
{
    //Write your code here.
    sort(arr.begin(),arr.end());
    for(int i=n-1;i>0;i--){
        int l=0,h=i-1;
        while(l<h){
            if(arr[i]==(arr[l]+arr[h]))
                return {arr[i],arr[h],arr[l]};
            else if((arr[l]+arr[h])<arr[i])
                l++;
            else
                h--;
        }
    }
    return {-1,-1,-1};
}

public static  ArrayList<Integer> findTriplets(int[] arr, int n) {
   Arrays.sort(arr);
   for(int i = n-1; i>=0; i--){
       int l = 0;
       int r = i-1;
       while(l<r){
           if(arr[l]+arr[r]==arr[i]){
               return new ArrayList<>(Arrays.asList(arr[i],arr[l],arr[r]));
           }
           if(arr[l]+arr[r]<arr[i])
                l++;
            else 
                r--;
       }
   }
   return new ArrayList<>();
}

```

### 3 Sum

You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.
An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that 

i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

1. You can return the list of values in any order. For example, if a valid triplet is {1, 2, -3}, then {2, -3, 1}, {-3, 2, 1} etc is also valid triplet. Also, the ordering of different triplets can be random i.e if there are more than one valid triplets, you can return them in any order.
2. The elements in the array need not be distinct.
3. If no such triplet is present in the array, then return an empty list, and the output printed for such a test case will be "-1".

```

#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    sort(arr.begin(),arr.end());
    vector<vector<int>> res;
    for(int i=0;i<n;i++){
        int l=i+1,h=n-1;
        while(l<h){
            if(arr[l]+arr[h]+arr[i]==K){
                res.push_back({arr[l],arr[h],arr[i]});
                while(l<h and arr[l]==arr[l+1])
                    l++;
                while(l<h and arr[h]==arr[h-1])
                    h--;
                while(arr[i]==arr[i+1])
                    i++;
                l++;
                h--;
            }
            else if(arr[l]+arr[h]<(K-arr[i]))
                l++;
            else
                h--;
        }
    }
    return res;
}
```
```
// Java Code
public static ArrayList<ArrayList<Integer>> findTriplets(int[] arr, int n, int K)  {
		Arrays.sort(arr);
		ArrayList<ArrayList<Integer>> result = new ArrayList<>();
		for(int i = 0;i<n;i++){
			int l = i+1;
			int r = n-1;
			while(l<r){
				int sum = arr[l]+arr[r]+arr[i];
				if(sum == K){
					result.add(new ArrayList<>(Arrays.asList(arr[l],arr[r],arr[i])));
					l++;
					r--;
					while(l<r && arr[l]==arr[l-1]) l++;
					while(l<r && arr[r]==arr[r+1]) r--;
					while(i+1<n && arr[i]==arr[i+1]) i++;
				}
				else if(sum<K) l++;
				else r--;
			}
		}
		return result;
	}
```

### Valid String
You have been given a string 'S' containing only three types of characters, i.e. '(', ')' and '*'.
A Valid String is defined as follows:

1. Any left parenthesis '(' must have a corresponding right parenthesis ')'.
2. Any right parenthesis ')' must have a corresponding left parenthesis '('.
3. Left parenthesis '(' must go before the corresponding right parenthesis ')'.
4. '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
5. An empty string is also valid.

Your task is to find out whether the given string is a Valid String or not.

##### Solution :

Let’s first focus on the problem when there are no asterisks. For this problem, we can just use a variable to count the unmatched ‘(‘. Clearly, we don't want the value of this variable to be less than 0 at any time and it should be 0 when the whole string has been matched.

```
open = 0;
for each c in string :
    if c== '('
        open++;
    else if c == ')'
        open--;
    if(open < 0) return false;        // It means we have a mismatched parenthesis ) which is closed without opening
return open == 0;
``` 

Now, when the asterisk is introduced, this variable or number becomes a range, indicating the number of possible unmatched ‘(‘ found. One asterisk just expands this range by 1 and we can use the same principle to check if the above criteria is within the range.
```
Algorithm :

Initialize ‘LEAST_OPEN’ to 0, which indicates the least number of unmatched ‘(‘ possible.
Initialize ‘MAXIMUM_OPEN’ to 0, which indicates the maximum number of unmatched ‘(‘ possible.
Loop for every character in ‘S’
If a ‘(‘ is found, increment both ‘LEAST_OPEN’ and ‘MAXIMUM_OPEN' by 1.
If a ‘)‘ is found, decrement both ‘LEAST_OPEN’ and ‘MAXIMUM_OPEN’ by 1.
If a ‘*’ is found, we have two choices
    Use it as a ‘(‘, hence increment ‘MAXIMUM_OPEN’ by 1.
    Use it as a ‘)‘, hence decrement ‘LEAST_OPEN’ by 1.
    Using it as an empty string won’t affect the range.
Set ‘LEAST_OPEN’ to maximum of 0 and ‘LEAST_OPEN’.
If ‘MAXIMUM_OPEN’ is less than zero, Return false.
Return true if the value of ‘LEAST_OPEN’ is 0, else false.

```

```
minOpen = 0;
maxOpen = 0;
for each c in string :
    if c=='(' :
        minOpen++;            // possibility of minimum open brackets is increased
        maxOpen++;            // possibility of maximum open brackets is increased
    else if c == ')':         // an open bracket has been closed
        minOpen--;            
        maxOpen--;
    else                      // an bracket either opened or closed both are possible
        maxOpen++;            // * considered as an open bracket, then maximum Possible open brackets count increased 
        minOpen--;            // * considered as an closed bracket, then minimum Possible open brackets count decreased
    minOpen = max(0,minOpen);
    if(maxOpen < 0) return false;
return minOpen == 0;
```
```
public static boolean checkValidString(String s) {
    int leastOpen = 0 ;
    int maxOpen = 0;
    for(char c : s.toCharArray()){
            if(c=='('){
                    leastOpen++;
                    maxOpen++;
            }
            else if(c==')'){
                    leastOpen--;
                    maxOpen--;
            }
            else{
                    maxOpen++;
                    leastOpen--;
            }
            leastOpen = Math.max(0,leastOpen);
            if(maxOpen<0) return false;
    }
    return leastOpen==0;
}
```


