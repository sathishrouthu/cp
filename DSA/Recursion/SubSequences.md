### Print all sub sequences of a given array

get every contingous or non contiguous sequence which follows the order of given array

**Approach**

- At each recursion call make a choice to pick or don't pick the element at i and move to next element.
- this recursion goes until i reaches end of the array.

```
void subs(int i,vector<int>& ds,vector<int> arr,vector<vector<int>>& ans)
{
  if(i==arr.size())
  {
    ans.push_back(ds);
    return ;
  }
  ds.push_back(arr[i]);
  subs(i+1,ds,arr,ans);
  ds.pop_back();
  subs(i+1,ds,arr,ans);
}
vector<vector<int>>  susequences(vector<int> arr)
{
  vector<int> ds;
  vector<vector<int>> ans;
  subs(0,ds,arr,ans);
  return ans;
}
```

### Combination Sum-I
Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

```
Example 1:

Input: array = [2,3,6,7], target = 7

Output: [[2,2,3],[7]]

```
**Approach** 

![image](https://user-images.githubusercontent.com/93826731/178167742-407fd3d1-e85d-4fb4-b5d1-f1f027bfe3db.png)


```
import java.io.*;
import java.util.*;
class Solution {
    private void findCombinations(int ind, int[] arr, int target, List < List < Integer >> ans, List < Integer > ds) {
        if (ind == arr.length) {
            if (target == 0) {
                ans.add(new ArrayList < > (ds));
            }
            return;
        }

        if (arr[ind] <= target) {
            ds.add(arr[ind]);
            findCombinations(ind, arr, target - arr[ind], ans, ds);
            ds.remove(ds.size() - 1);
        }
        findCombinations(ind + 1, arr, target, ans, ds);
    }
    public List < List < Integer >> combinationSum(int[] candidates, int target) {
        List < List < Integer >> ans = new ArrayList < > ();
        findCombinations(0, candidates, target, ans, new ArrayList < > ());
        return ans;
    }
}

```

### Combination Sum - II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates 
where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Input: candidates = [10,1,2,7,6,1,5], target = 8

Output: 

[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]



```
void rec(int ind,int target,vector<int>& ds,vector<int> cand,vector<vector<int>>& ans){
        if (target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<cand.size();i++){
            if(i>ind && cand[i]==cand[i-1]) continue;
            if(cand[i]>target) break;
            ds.push_back(cand[i]);
            rec(i+1,target-cand[i],ds,cand,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        rec(0,target,ds,candidates,ans);
        return ans;
    }
```

### Subset Sum : Sum of all Subsets

Given an array print all the sum of the subset generated from it, in the increasing order.

```
Example 1:

Input: N = 3, arr[] = {5,2,1}

Output: 0,1,2,3,5,6,7,8

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are 
[ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8
```

**Intuition:** The main idea is that on every index you have two options either to select the element to add it to your subset(pick) or not select the element at that index and move to the next index(non-pick).

**Approach:** Traverse through the array and for each index solve for two arrays, one where you pick the element,i.e add the element to the sum or don’t pick and move to the next element, recursively, until the base condition. Here when you reach the end of the array is the base condition.

![image](https://user-images.githubusercontent.com/93826731/178167972-d6c981cd-f0e1-446c-b5ad-82f5e9668865.png)

```
import java.util.*;
class Sathish{
    static void func(int ind, int sum, ArrayList < Integer > arr, int N, ArrayList < Integer > sumSubset) {
        if (ind == N) {
            sumSubset.add(sum);
            return;
        }

        // pick the element 
        func(ind + 1, sum + arr.get(ind), arr, N, sumSubset);

        // Do-not pick the element
        func(ind + 1, sum, arr, N, sumSubset);
    }

    static ArrayList<Integer> subsetSums(ArrayList < Integer > arr, int N) {
        ArrayList < Integer > sumSubset = new ArrayList < > ();
        func(0, 0, arr, N, sumSubset);
        Collections.sort(sumSubset);
        return sumSubset;
    }
}

```

### Subset – II | Print all the Unique Subsets
Given an array of integers that may contain duplicates the task is to return all possible subsets(Power set).
Return only unique subsets and they can be in any order.

```
Input: array[] = [1,2,2]

Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]

Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.

```
<a href="https://takeuforward.org/data-structure/subset-ii-print-all-the-unique-subsets/" > Read this to get better understanding</a>


We start with a recursion call and in each nth recursion call we want generate the subset of size n.
To avoid duplicates we simply check if the current element is already picked up in current recursion call.

Lets  understand  with an example where arr = [1,2,2 ].

Initially start with an empty data structure. In the first recursion, call make a subset of size one, in the next recursion call a subset of size 2, and so on. But first, in order to make a subset of size one what options do we have?

We can pick up elements from either the first index or the second index or the third index. However, if we have already picked up two from the second index, picking up two from the third index will make another duplicate subset of size one. Since we are trying to avoid duplicate subsets we can avoid picking up from the third index. This should give us an intuition that whenever there are duplicate elements in the array we pick up only the first occurrence.

The next recursion calls will continue from the point the previous one ended.


* Sort the input array.Make a recursive function that takes the input array ,the current subset,the current index and  a list of list/ vector of vectors to contain the answer.
* Try to make a subset of size n during the nth recursion call and consider elements from every index while generating the combinations. Only pick up elements that are appearing for the first time during a recursion call to avoid duplicates.
* Once an element is picked up, move to the next index.The recursion will terminate when the end of array is reached.While returning backtrack by removing the last element that was inserted.

```
class Solution {
    public void findSubs(int ind,int[] nums,List<Integer> ds,List<List<Integer>> ans){
        ans.add(new ArrayList<>(ds));
        for(int i=ind;i<nums.length;i++){
            if(i!=ind&&nums[i]==nums[i-1]) continue;
            ds.add(nums[i]);
            findSubs(i+1,nums,ds,ans);
            ds.remove(ds.size()-1);
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        findSubs(0,nums,new ArrayList<>(),ans);
        return ans;
    }
}

```

