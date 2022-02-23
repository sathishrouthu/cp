// Print all sub sequences of a given array whose sum == s (given sum )
// get every contingous or non contiguous sequence which follows the order of given array
//
#include<bits/stdc++.h>
using namespace std;
void subs(int i,vector<int>& ds,vector<int> arr,int& s,int sum,vector<vector<int>>& ans)
{
  if(i==arr.size())
  {
    if(s==sum)
    {
      ans.push_back(ds);
      return;
    }
   return;
  }
  ds.push_back(arr[i]);
  s+=arr[i];
  subs(i+1,ds,arr,s,sum,ans);
  ds.pop_back();
  s-=arr[i];
  subs(i+1,ds,arr,s,sum,ans);
}

int main()
{
  vector<int> arr={2,1,1,3,-1};
  vector<int> ds;
  vector<vector<int>> ans;
  int s=0;
  subs(0,ds,arr,s,2,ans);
  for(vector<int> i : ans)
  {
    for(int j : i)
    {
      cout<<j<<"  ";
    }
    cout<<endl;
  }
  return 0;
}
