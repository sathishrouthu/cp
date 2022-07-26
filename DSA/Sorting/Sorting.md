
### Sort an Array in the Wave form
```
You have been given an unsorted array ‘ARR’.
Your task is to sort the array in such a way that the array looks like a wave array.
1. ‘ARR[0]’ must be greater than or equal to ‘ARR[1]’.
2. There can be multiple arrays that look like a wave array but you have to return only one.
```
![image](https://user-images.githubusercontent.com/93826731/180316973-3d0f75fb-18a9-456e-8832-085d8af71b23.png)

Try to solve this problem in linear time complexity.

```
vector<int> waveFormArray(vector<int> &arr, int n){
    for(int i=0;i<n-1;i++){
        if(i%2==0){
            if(arr[i]>=arr[i+1])
                continue;
            else
                swap(arr[i],arr[i+1]);
        }
        else{
            if(arr[i]<=arr[i+1])
                continue;
            else
                swap(arr[i],arr[i+1]);
        }
    }
    return arr;
}
```



### Sort An Array According To The Count Of Set Bits
```
You are given an array consisting of N positive integers, and your task is to sort the array in decreasing order of count of set bits in the binary 
representation of the integers present in the array. In other words, you have to modify the array such that an integer with more number of set bits 
should appear before the integer which has lesser number of set bits in its binary representation.

1. If any two numbers have the same count of set bits, then in the sorted array they will appear in the order in which they appear in 
the original array. For example, let the array be { 2, 4, 3}, in this case, both 2 and 4 have the same number of set bits so the answer 
will be {3, 2, 4} and not {3, 4, 2}, because in the original array 2 appears before 4.

2. The array may contain duplicate elements.
```


**By using std::sort()**
```
int countsetBits(int n){
    int c=0;
    while(n>0){
        n=n&(n-1);
        c++;
    }
    return c;
}
int cmp(int a,int b){
    int c1 = countsetBits(a);
    int c2 = countsetBits(b);
    return c1>c2?1:0;
}
void sortSetBitsCount(vector<int>& arr, int size)
{
    vector<vector<int>> count()
    stable_sort(arr.begin(),arr.end(),cmp);
}
```
**By using Count Sort()**

```
int countSetBits(int n){
    int c=0;
    while(n>0){
        n=n&(n-1);
        c++;
    }
    return c;
}
void sortSetBitsCount(vector<int>& arr, int size)
{
    vector<vector<int>> count(32);
    for(int i=0;i<size;i++){
        int c = countSetBits(arr[i]);
        count[c-1].push_back(arr[i]);
    }
    int idx=0;
    for(int i=31;i>=0;i--){
        for(int j=0;j<count[i].size();j++)
            arr[idx++] = count[i][j];
    }
}
```


### Sort a Binary Array
A binary array is an array consisting of only 0s and 1s.
You are given a binary array "arr" of size ‘N’. Your task is to sort the given array and return this array after sorting.

Expected space comlexity: O(1)
Expected time complexity: O(n)

as we are having only 0s and ones.
we can sort this by swapping the elements internally in such a way that all 0s comes to front and 1s goes to back.
1. take two pointer i and j .. i points to 0s and j points to 1s
2. move i forward until you encounters a 1, move j backward until you enounter a 0,
3. if i<j that means there are some elements in between them , ==> swap arr[i] and arr[j] and i++ , j--
4. do thish until i crosses j.

```
vector<int> sortBinaryArray(vector<int> arr, int n)  {
    int i=0,j=n-1;
    while(i<=j){
        while(arr[i]==0)
            i++;
        while(arr[j]==1)
            j--;
        if(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return arr;
}
```
### Relative Sorting

Given two arrays ‘ARR’ and ‘BRR’ of size ‘N’ and ‘M’ respectively. Your task is to sort the elements of ‘ARR’ in such a way that the relative order among the elements will be the same as those are in ‘BRR’. For the elements not present in ‘BRR’, append them in the last in sorted order.
```
Ex: 
Consider the arrays as ARR = { 9, 5, 8, 4, 6, 5 } and BRR = { 8, 4, 5 }
The output for the above example  is { 8, 4, 5, 5, 6, 9 }.
```
Elements of ‘BRR’ are non repeating.

**Solution** :
The above problem can be solved by using a map to count each element in ARR.
first we count th frequency of each element in ARR.
then we traverse the BRR one by one
for each element in BRR we take it into answer no. of times it occured in ARR.
```
example  :  ARR = { 3,2,4,1,4,3,2,5,1,3,2 }
            BRR = { 2,1,4 }
            
     Count frequency :
                   {    3 : 3,
                        2 : 3,
                        4 : 2,
                        1 : 2,
                        5 : 1  }
     Initialize Answer = {};
     for x in BRR :
        add x to Answer freq[x] no. of times.
        remove x from freq.
     if freq.size()!=0  ( remaining elements )
        add them to answer in the same way as above.            
```
```
#include<bits/stdc++.h>
vector<int> relativeSorting(vector<int> &arr, vector<int> &brr, int n, int m)
{
    unordered_map<int,int> mp;
    for(int i : arr)
        mp[i]++;
    vector<int> v;
    for(int x : brr){
        while(mp[x]>0){
            mp[x]--;
            v.push_back(x);
        }
        mp.erase(x);
    }
    vector<int> rem;
    if(mp.size()!=0)
    for(auto p : mp){
        while(mp[p.first]!=0){
            rem.push_back(p.first);
            mp[p.first]--;
        }
    }
    sort(rem.begin(),rem.end());
    for(int i: rem)
        v.push_back(i);
    return v;
}
```


### Min no. of swaps required to sort an array

