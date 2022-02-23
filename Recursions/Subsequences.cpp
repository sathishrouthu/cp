// Print all sub sequences of a given array
// get every contingous or non contiguous sequence which follows the order of given array
//
#include<bits/stdc++.h>
using namespace std;
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

int main()
{
  vector<int> arr={2,1,3};
  vector<int> ds;
  vector<vector<int>> ans;
  subs(0,ds,arr,ans);
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
