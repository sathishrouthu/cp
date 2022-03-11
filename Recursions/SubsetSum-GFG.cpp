/*

Given a list arr of N integers, print sums of all subsets in it in sorted order.

*/
    void rec(int ind,int sum,vector<int> arr,vector<int>& ans){
        if(ind>=arr.size()){
            ans.push_back(sum);
            return;
        }
        rec(ind+1,sum+arr[ind],arr,ans);
        rec(ind+1,sum,arr,ans);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        rec(0,0,arr,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
