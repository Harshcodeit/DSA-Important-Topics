#include<bits/stdc++.h>
using namespace std;

using ll=long long;
vector<ll> f(int i,int j,vector<vector<int>>&grid,vector<vector<vector<ll>>>&dp,vector<vector<bool>>&used){
    if(i==0 && j==0) return dp[0][0]={grid[0][0],grid[0][0]};
    
    if(used[i][j]) return dp[i][j];
    int dr[2]={-1,0};
    int dc[2]={0,-1};
    ll maxi=-1e18,mini=1e18;
    for(int k=0;k<2;k++){
        int nr=i+dr[k];
        int nc=j+dc[k];
        if(nr>=0 && nc>=0){
            vector<ll>temp=f(nr,nc,grid,dp,used);
            temp[0]*=grid[i][j];
            temp[1]*=grid[i][j];
            maxi=max({maxi,temp[0],temp[1]});
            mini=min({mini,temp[0],temp[1]});
        }
    }
    used[i][j]=true;
    return dp[i][j]={maxi,mini};
}
int main(){
    int mod=1e9+7;
    int m,n;
    cin>>m>>n;
    vector<vector<int>>grid(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) cin>>grid[i][j];
    }

    vector<vector<vector<ll>>>dp(m,vector<vector<ll>>(n,vector<ll>(2)));
    vector<vector<bool>>used(m,vector<bool>(n,false));

    f(m-1,n-1,grid,dp,used);
    if(dp[m-1][n-1][0] < -1) return -1;
    else return dp[m-1][n-1][0] % mod;
}