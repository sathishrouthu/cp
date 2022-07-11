### Permutations (Leetcode-46)

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```
#### Solution-1  with O(N) space

**Approach:** We have given the nums array, so we will declare an ans vector of vector that will store all the permutations also declare a data structure.

Declare a map and initialize it to zero and call the recursive function

Base condition:

When the data structure’s size is equal to n(size of nums array)  then it is a permutation and stores that permutation in our ans, then returns it.

**Recursion:**

Run a for loop starting from 0 to nums.size() – 1. Check if the frequency of i is unmarked, if it is unmarked then it means it has not been picked and then we pick. And make sure it is marked as picked.

Call the recursion with the parameters to pick the other elements when we come back from the recursion make sure you throw that element out. And unmark that element in the map.


![image](https://user-images.githubusercontent.com/93826731/178169355-b8048b82-f48d-4ea8-ad35-833632a8b0d1.png)

```
class Solution {
    private void rec(int[] nums,List<Integer> ds,List<List<Integer>> ans,boolean[] freq){
        if(ds.size()==nums.length){
            ans.add(new ArrayList<>(ds));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(!freq[i]){
                freq[i]=true;
                ds.add(nums[i]);
                rec(nums,ds,ans,freq);
                ds.remove(ds.size()-1);
                freq[i] = false;
            }
        }
        
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans =new ArrayList<>();
        boolean[] freq = new boolean[nums.length];
        rec(nums,new ArrayList<>(),ans,freq);
        return ans;
    }
}
```


#### Solution -2 Without extra space :

**Base condition:**

Whenever the index reaches the end take the nums array and put it in ans vector and return.

**Recursion:**

Go from index to n – 1 and swap. Once the swap has been done call recursion for the next state.
After coming back from the recursion make sure you re-swap it because for the next element the swap will not take place.


![image](https://user-images.githubusercontent.com/93826731/178170637-a78de5e7-c64e-4135-bd59-e601fc03adc8.png)

```
class Solution {
public:
    void rec(int ind,vector<int>& nums,vector<vector<int>>& ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            rec(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        rec(0,nums,ans);
        return ans;
    }
};
```
