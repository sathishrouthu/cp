### Pair Sum

You are given an integer array 'ARR' of size 'N' and an integer 'S'. 
Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.

- Each pair should be sorted i.e the first value should be less than or equals to the second value. 

- Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.

```
vector<vector<int>> pairSum(vector<int> &arr, int s){
    sort(arr.begin(),arr.end());
    vector<vector<int>> result;
    for(int i=0;i<arr.size();i++){
        int comp = s-arr[i];
        vector<int> pair(2);
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]==comp){
                pair[0] = arr[i]<arr[j]?arr[i]:arr[j];
                pair[1] = s-pair[0];
                result.push_back(pair);
            }
        }
    }
    return result;
}
```
