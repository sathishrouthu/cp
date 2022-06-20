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
        add (arr[i],arr[l],arr[r])  to final answer
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
        area = (j-i)\*min(arr[i]\*arr[j]);
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


### Valid String
You have been given a string 'S' containing only three types of characters, i.e. '(', ')' and '*'.
A Valid String is defined as follows:

1. Any left parenthesis '(' must have a corresponding right parenthesis ')'.
2. Any right parenthesis ')' must have a corresponding left parenthesis '('.
3. Left parenthesis '(' must go before the corresponding right parenthesis ')'.
4. '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
5. An empty string is also valid.

Your task is to find out whether the given string is a Valid String or not.





