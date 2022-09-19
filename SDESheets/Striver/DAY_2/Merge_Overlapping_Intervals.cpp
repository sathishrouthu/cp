/*
 Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.
 
 Example 1: 

Input: intervals=[[1,3],[2,6],[8,10],[15,18]]

Output: [[1,6],[8,10],[15,18]]

Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
 intervals.

*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> result;
    if(n==0)
        return result;

    sort(intervals.begin(),intervals.end());
    vector<int> temp = intervals[0];
    for(auto v : intervals){
        if(v[0] <= temp[1]){
            temp[1] = max(temp[1],v[1]);
        }
        else{
            result.push_back(temp);
            temp = v;
        }
    }
    result.push_back(temp);
    return result;
}
