// Print all sub sequences of a given array
// get every contingous or non contiguous sequence which follows the order of given array
//

void subs(int i,vector<int>& ds,vector<int> arr,vector<vector<int>>& ans)
{
  if(i==arr.size())
  {
    ans.push_back(ds);
    return ;
  }
  subs(i+1,ds,arr,ans)
  ds.pop_back()
  subs(i+1,ds,arr,ans)
}

int main()
{
  vector<int> arr={2,1,3,4};
  vector<int> ds;
  subs(0,ds,arr,ans);
  for(auto i : ans)
  {
    for(int j : i)
    {
      cout<<j<<"  ";
    }
    cout<<endl;
  }
}
