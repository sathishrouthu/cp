#include<bits/stdc++.h>
using namespace std;

// Recursion
int f(int i,int j,vector< vector< int> > &mat){
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0 || mat[i][j]==-1)
        return 0;
    int up = f(i-1,j,mat);
    int left = f(i,j-1,mat);
    return up+left;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    return f(n-1,m-1,mat);
}

// Memoization
int mod = 1e9+7;

int f(int i,int j,vector< vector< int> > &mat,vector<vector<int>> &dp){
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0 || mat[i][j]==-1)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = f(i-1,j,mat,dp);
    int left = f(i,j-1,mat,dp);
    return dp[i][j] = (up+left)%mod;
}

int mazeObstacles(int n, int m, vector< vector<int> > &mat) {    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,mat,dp);
}

// Tabulation


int mazeObstacles(int m, int n, vector< vector<int> > &mat) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    dp[i][j] = 1;
                else if(mat[i][j]==-1)
                    dp[i][j] = 0;
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = (up+left)%mod;
                }
            }
        }
    return dp[m-1][n-1];
}

