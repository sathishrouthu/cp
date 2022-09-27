
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. 
Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

```
Example 1:

Input: 
n = 4, arr1[] = [1 4 8 10] 
m = 5, arr2[] = [2 3 9]

Output: 
arr1[] = [1 2 3 4]
arr2[] = [8 9 10]
```
**Naive Approach  : **

Merge them into a temp array (like merge sort) and then add elements to arr1 and arr2.

T C : O(N) + O(N)

S.C : O(N)

**Without space : **

We can think of Iterating in arr1 and whenever we encounter an element that is greater than the first element of arr2, just swap it. Now rearrange the arr2 in a sorted manner, after completion of the loop we will get elements of both the arrays in non-decreasing order.
```
- Use a for loop in arr1.
- Whenever we get any element in arr1 which is greater than the first element of arr2,swap it.
- Rearrange arr2.
- Repeat the process.

```

```
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(n==0)
        return;

    for(int i=0;i<m;i++){

        if(nums1[i]>nums2[0]){
            swap(nums1[i],nums2[0]);
        }

        int first = nums2[0];
        int k=1;
        while(k<n && nums2[k]<first){
            nums2[k-1] = nums2[k];
            k++;
        }
        nums2[k-1] = first;
    }
}

```


