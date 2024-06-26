# Sliding Window

Read this  :  [Sliding Window](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template/)

Substring problems template : [Sliding Window substrings/ subarray ](https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems/)

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

// Java

public static ArrayList<Integer> smallestSubarrayWithKDistinct(ArrayList<Integer> a, int K){
       HashMap<Integer,Integer> map = new HashMap<>();
       int n = a.size();
       int start = 0;
       int end = n;
       int i = 0;
       int j = 0;
       while(j<n){
           map.put(a.get(j), map.getOrDefault(a.get(j),0)+1);
           while(map.size()==K){
               if((j-i) < (end-start)){
                   start = i;
                   end = j;
               }
               map.put(a.get(i), map.get(a.get(i))-1 );
               if(map.get(a.get(i)) == 0 ) 
                   map.remove(a.get(i));
               i++;
           }
           j++;
       }
       if(end-start == n){
           return new ArrayList<>(Arrays.asList(-1));
       }
       ArrayList<Integer> result = new ArrayList<>(Arrays.asList(start,end));
       return result;
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
 - find the min of 3 elements at current
 - find diffrenece b/w max and min and update the results as below:
       if found difference is less than previously found diff,
       it means we have a less difference value which is better than previously found difference
 we have to minimize this difference to get optimal value of min difference of 3 elements
 inorder to minimize above value we have to increase the least valueamong 3 values.
 since the arrays are sorted we increase the pointer which has the least value among all 3;
 ```
 
 ```
public static int threePointer(ArrayList<Integer> X, ArrayList<Integer> Y, ArrayList<Integer> Z) {
        int A = X.size();
        int B = Y.size();
        int C = Z.size();
        int i = 0;
        int j = 0;
        int k = 0;
        int minDiff  = Integer.MAX_VALUE;
        int result = Integer.MAX_VALUE;
        while(i<A && j<B && k <C){
            int Xi = X.get(i);
            int Yj = Y.get(j);
            int Zk = Z.get(k);
            int high = Math.max(Xi,Math.max(Yj,Zk));
            int low = Math.min(Xi,Math.min(Yj,Zk));
            if(high - low < minDiff ){
                minDiff = high-low;
                result = Math.min(result,Math.abs(minDiff));
            }
            if(Xi == low) i++;
            else if(Yj==low) j++;
            else k++;
        }
        return result;
    }
 
 ```

### Shortest Substring with all characters

You have been given a string 'S' which only consists of lowercase English-Alphabet letters. Your task is to find the shortest (minimum length) substring from 'S' which contains all the characters of 'S' at least once.

If there are more than one substring with the shortest length, then find one which appears earlier in the string ‘S’ i.e. substring whose starting index is lowest.

**Brute force approach**

* count all the distinct characters in the given string and store it in the "DIST".
* we try to generate all possible substring by using a nested for loops
* from now generate a substring and check for
* if the no. of characters in substring equals to the "DIST".
* check the length of current substring and compare with previous min_length and note the starting index.
```
dist = distinct characters.
start=0;
min_length = INT_MAX;
for i-->0 to n-1
  Set = {};
  for j-->i to n-1
     Set.insert(str[j]);
     if (Set.size()==dist)
         if( j-i < min_length )
               min_length = j-i;
               start = i;
return str.substr(start,minlength+1);

```

```
#include<bits/stdc++.h>
string shortestSubstring(string s)
{
    // Write your code here.
    int n = s.length();
    unordered_set<char> Set;
    for( char i : s)
        Set.insert(i);
    int dist = Set.size();
    int start,min_length=INT_MAX;
    for(int i=0;i<n;i++){
        Set = {};
        for(int j=i;j<n;j++){
            Set.insert(s[j]);
            if(Set.size()==dist){
                if(j-i < min_length){
                    start = i;
                    min_length = j-i;
                }
            }
        }
    }
    return s.substr(start,min_length+1);
    
}

```

**Efficient Approach**
```
- Use two pointers i and j to keep a window as substring and then we use this window to satisfy our conditions

- initialize a hash set (freq) of <char,int> to keep track of no.of dist characters in our window.
- there are two main operations to be performed on window:
=> expand window : increase freq of new character of window in hashset and j++;
=> shrink window : decrease freq of starting character of window in hashset and i++;

- we expand the window until we find a substring that contains all characters of whole string.
- if we find such substring we update the results and  try to shrink the window to get minimum length.

```

```
- count no. of distinct characters in given string by using a set and store it in distinct.
- Initialize empty hashset
- Initialize i=0,j=0,start=0,min_length = n;
- while(j<n)
     freq[str[j]]++;
     while(freq.size()==distinct)
           if(j-i < min_length)
                min_length = j-i
                start=i
           freq[str[i]]--;
           if(freq[s[i]]==0)
               freq.erase(s[i])
           i++;
     j++
- return str.substr(start,min_length+1);     
```

```
#include<bits/stdc++.h>
string shortestSubstring(string s)
{
    int n = s.length();
    int start = 0,i=0,j=0,min_length = n;
    unordered_set<int> Set;
    for(char i:s)
        Set.insert(i);
    int dist = Set.size();
    unordered_map<char,int> freq;
    int count=0;
    while(j<n){
        freq[s[j]]++;
        while(freq.size()==dist){
            if(j-i < min_length){
                min_length = j-i;
                start = i;
            }
            freq[s[i]]--;
            if(freq[s[i]]==0)
                freq.erase(s[i]);
            i++;
        }
        j++;
    }
    return s.substr(start,min_length+1);
}

// Java Code

public static String shortestSubstring(String s) {
		int n = s.length();
		Set<Character> set = new HashSet<>();
		for(char c : s.toCharArray()) set.add(c);
		int distinct = set.size();
		HashMap<Character,Integer> map = new HashMap<>();
		int start = 0,end = n-1;
		int i = 0,j=0;
		while(j<n){
			map.put(s.charAt(j),map.getOrDefault(s.charAt(j), 0)+1);
			while(map.size()==distinct){
				if(j-i < end-start){
					start = i;
					end = j;
				}
				map.put(s.charAt(i), map.get(s.charAt(i))-1 );
				if(map.get(s.charAt(i)) == 0) 
						map.remove(s.charAt(i));
				i++;
			}
			j++;
		}
		return s.substring(start, end+1);
	}
```

