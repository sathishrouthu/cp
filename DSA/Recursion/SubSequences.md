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
