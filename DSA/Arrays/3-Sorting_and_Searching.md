### Search in a rotated Sorted array
<a href="https://www.linkedin.com/posts/mayank-singh-1004981a4_search-in-rotated-sorted-array-ii-activity-6914044080352018432-fhId?utm_source=linkedin_share&utm_medium=member_desktop_web
"> Refer this post for explanation!!</a>

 ```
int search(int* arr, int n, int key) {
    int l=0,h=n-1;
    int mid;
    while(l<=h){
        mid=l+(h-l)/2;
        if(arr[mid]==key)
            return mid;
        if(arr[mid]==arr[h]&&arr[mid]==arr[l]){
            l++;
            h--;
        }
        else if(arr[mid]<=arr[h])
            if(arr[mid]<key && key<=arr[h])
                l=mid+1;
            else
                h=mid-1;
        else if(arr[mid]>=arr[l])
            if(arr[mid]>key && arr[l]<=key)
                h=mid-1;
            else
                l=mid+1;
    }
    return -1;
}

```


### Form a Triangle
You are given an integer of array/list 'ARR' of length ‘N. You are supposed to return true
if it is possible to construct at least one non-degenerate triangle using values of array/list 
as sides of the triangle, otherwise, return false.

Ex:

ip : 4 2 1 3 2

op : YES

if we choose the sides as { 2,3,4} or {2,2,1} or {2,2,3} then it is possible to form a non-degenerate triangle.

ip : 12 3 7 4 28

op : NO

In the first test case, there is no possible way to choose three elements such that they will form the sides of a triangle.

```
bool possibleToMakeTriangle(vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-2;i++){
        if(arr[i]+arr[i+1]>arr[i+2])
            return true;
    }
    return false;
}

```


### Count Smaller or Equal elements in array
You are given two arrays of integers. Let's call the first array A and the second array B. 
A finds the number of elements in array B that are smaller than or equal to that element for every array element.
<pre>
A = [2, 3, 0] , B = [5, 1]

For the first index, A[0] = 2
In array B only 1 is less than 2. Therefore the answer for the first index is 1.

For the second index, A[1] = 3
In array B only 1 is less than 3. Therefore the answer for the second index is also 1.

For the third index, A[2] = 0
Both the elements of array B are greater than 0. 
Therefore the answer for the third index is 0.

Hence, the final answer is [1,1,0] in this case.
</pre>
<pre>
My Approach:
it is a problem of  finding upperbound using binary search.
given a sorted array and an integer k then the upperbound of k is the index of smallest value that is greater than k.

from the given problem we need to find the upper bound of each element of array A in the array B so,

1. initialize empty vector v={};
2. for i in A:
 - x = upperbound of i in Array B.
 - add x to v
3. return v;

how to find upper bound?
by using binary search :
let arr = [1 2 3 3 4 5] and K=3
to know upper bound of k
we divide search space into faourable and unfavourable
[ 1 2 3 3 4 5 ]
  U U U U F F
if we are in U move right => if (arr[mid]<=k) : l=mid+1
else move left : h=mid-1;
finally our answer will be at l;
</pre>
so finally:
```
while(l<=h){
 mid=(l+h)/2;
 if (nums[mid]>k)
  h=mid-1;
 else
  l=mid+1;
}
return l;
```

for the above given problem :
we need to sort the Array B inorder to apply binary search;

```
vector <int> countSmallerOrEqual(int * a, int * b, int n, int m) {
    sort(b,b+m);
    vector<int> v;
    int l,h,mid;
    for( int i=0;i<n;i++){
        l=0;
        h=m-1;
        while(l<=h){
            mid=(l+h)/2;
            if(b[mid]>a[i])
                h=mid-1;
            else
                l=mid+1;      
        }
        v.push_back(l);
    }
    return v;
}

```

### Algorithm to find best insert position in sorted array
You are given a sorted array 'A' of length 'N' with distinct integers and a target integer 'M'.
You need to return the position of 'M' if it existed in the array 'A'. If it already exists in 'A', return that position. 
(0-based indexing)

```
int bestInsertPos(vector<int> arr, int n, int m)
{
    // Write your code here.
    int l=0,h=n-1,mid;
    while(l<=h){
        mid=(l+h)/2;
        if(arr[mid]==m)
            return mid;
        if(arr[mid]>m)
            h=mid-1;
        else
            l=mid+1;
    }
    return l;
}

```
