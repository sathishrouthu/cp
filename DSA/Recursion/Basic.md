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

