### Towers of Hanoi

```
Problem :
you are given 3 rods numbered 1,2,3
rod-1 has n no.of disks placed in it in a sorted order
```
![image](https://user-images.githubusercontent.com/93826731/178032998-4cb1ab2a-8aa7-4b9f-ae5e-95c6acd0d3d9.png)
```
we have to move the n disks from rod1 to rod-2 or rod-3 by following below conditions:

1. You can only move one disk in one move. 
2. You can not place a larger disk on top of a smaller disk.
3. You can only move the disk at the top of any rod.

```

Solution :
```
It can be solved by using recursion such that we have to divide the prblem into smaller problem gradually and solve from bottom

first of all let us assume we have a single disk in rod-1(source) then we simply move it to the rod-3 (destination).
if we have 2 disks we move top disk to helper rod-2 and move 2nd disk to destination rod-3 and then the previous disk at rod-2 will be moved to destination rod-3.
if we have 3 disks 
              we move top 2 disks to the rod-2 by using rod-3 as an helper rod Now we move 3rd disk to the destination rod-3 in the above way.
              we move the 2 disks at rod-2 to the destination rod-3 by using rod1 as a helper in same way as above.
              
              
if we clearly observe the above approach in 3rd point:
                    first we are moving top n-1 disks to rod-2 and then moving last nth disk to rod-3 using rod-3 as helper.
                    then we are moving the n-1 disks from rod-2 to rod-3 using rod-1 as helper.
                    
```

```
TOH(int n,source,helper,destination)
if(n==1)
  move 1st disk from source to destination
TOH(n-1,source,destination,helper)                          //move n-1 disks from source to helper by using destination as helper
move nth disk(largest disk) from source to destionation
TOH(n-1,helper,source,destination)                          //move n-1 disks from helper to destination using source as helper

```


```
void rec(int n,int src,int helper,int destination,vector<vector<int>>& ans){
    if(n==1){
        ans.push_back({src,destination});
        return;
    }
    
    rec(n-1,src,destination,helper,ans);
    ans.push_back({src,destination});
    rec(n-1,helper,src,destination,ans);
}

vector<vector<int>> towerOfHanoi(int n)
{
    vector<vector<int>> ans;
    rec(n,1,2,3,ans);
    return ans;
    
}

```


### Family Structure
```
Aakash is a member of Ninja club. He has a weird family structure. 
Every male member (M) gives birth to a male child first and then a female child, whereas 
every female (F) member gives birth to a female child first and then to a male child. Aakash analyses this pattern
and wants to know what will be the Kth child in his Nth generation. Can you help him?
```
![image](https://user-images.githubusercontent.com/93826731/178041506-a9245a3c-7f99-4f92-9854-962cb0a9e82b.png)
```
The generation tree starts with a male member i.e. Aakash. 
Every member has exactly two children. 
```
**Observations from the problem:**
1. Every generation starts with a "Male" gender : if k==1 or n==1 then Gender = Male; ==> Base case
2. if the child is the first child of parent then he is same gender as parent
3. else the child gender is opposite to the parent's gender.
4. to find gender of kth child in nth generation we have to find his parent' gender
5. if child is kth child in nth generation then parent will be (k+1)/2 th child in (n-1)th generation.

```
To check whether the child is first child to parent or not:
we need to check if k is odd or not 
if k==1 or k==3 or k==5 or ...  then he is first child
```

```
string kthChildNthGeneration(int n, long long int k)
{
    if(n==1 || k==1)
        return "Male";
    long long int par=(k+1)/2;
    string parGen = kthChildNthGeneration(n-1,par);
    if( k%2 !=0 ){                    // checking first child or not
        return parGen;
    }
    else
        return (parGen == "Male")?"Female":"Male";
}

```

### Return Subsets Sum to K

Given an integer array 'ARR' of size 'N' and an integer 'K', return all the subsets of 'ARR' which sum to 'K'.

Subset of an array 'ARR' is a tuple that can be obtained from 'ARR' by removing some (possibly all) elements of 'ARR'.

```
Example:
arr = 2 4 6
k = 6

ans = {2,4} , {6}

For the array'ARR' = {2, 4, 6}, we can have subsets {}, {2}, {4}, {6}, {2, 4}, {2, 6}, {4, 6}, {2, 4, 6}. Out of these 8 subsets, {2, 4} and {6} sum to the given 'K' i.e. 6.

```

```
void findSub(int i,int sum,vector<int>& ds,vector<int> arr,vector<vector<int>>& ans){
    if(i==arr.size()){
        if(sum == 0)
            ans.push_back(ds);
        return;
    }
    ds.push_back(arr[i]);
    findSub(i+1,sum-arr[i],ds,arr,ans);
    ds.pop_back();
    findSub(i+1,sum,ds,arr,ans);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int> ds;
    vector<vector<int>> ans;
    findSub(0,k,ds,arr,ans);
    return ans;
}

```

