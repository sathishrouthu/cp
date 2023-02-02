#include<bits/stdc++.h>
using namespace std;


int f(int n,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(n<0)
        return 0;
    if(dp[n][last]!=-1) return dp[n][last];

    int maxi = INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=last){
            maxi = max( maxi, f(n-1,i,points,dp)+points[n][i]);
        }
    }
    return dp[n][last] = maxi;
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // vector<vector<int>> dp(n,vector<int>(4,-1));

    vector<int> prev(4,0);
    for(int last = 0;last<4;last++){
        int maxi = INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=last)
            maxi = max(maxi,points[0][i]);
        }
        prev[last] = maxi;
    }
    for(int i=1;i<n;i++){
        vector<int> curr(4,0);
        for(int last = 0;last<4;last++){
            int maxi = INT_MIN;
            for(int k=0;k<3;k++){
                if(k!=last){
                    maxi = max(maxi, prev[k]+points[i][k]);
                }
            }
            curr[last] = maxi;
        }
        prev = curr;
    }
    return prev[3];

}

int main(){
    return 0;
}