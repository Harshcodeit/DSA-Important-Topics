#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>&dungeon,int hp){
    int m=dungeon.size(),n=dungeon[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));//hp at dp[i][j]
    dp[0][0]=hp+dungeon[0][0];

    for(int row=1;row<m;row++){
        if(dp[row-1][0] <=0) break;
        dp[row][0] += dp[row-1][0] + dungeon[row][0];
    }
    for(int col=1;col<n;col++){
        if(dp[0][col-1] <=0) break;
        dp[0][col] += dp[0][col-1] + dungeon[0][col];
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(dp[i-1][j] <=0 && dp[i][j-1] <=0) continue;
            dp[i][j]=dungeon[i][j] + max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m-1][n-1] > 0;
}
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m=dungeon.size(),n=dungeon[0].size();
    if(m== 1 && n==1) return dungeon[0][0]< 0 ? abs(dungeon[0][0])+1 : 1;

    int l=1,r=(m+n-2)*1000;
    int res=INT_MAX;

    while(l <= r){
        int mid=l+(r-l)/2;
        if(check(dungeon,mid)){
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return res;
}

// recursive sol, T-O(mn)
int dp[200][200];
int f(int i,int j,vector<vector<int>>&grid){
    int m=grid.size(),n=grid[0].size();
    if(i==m-1 && j==n-1){
        return grid[i][j] < 0 ? abs(grid[i][j])+1 : 1;
    }
    if(i>=m || j>=n) return INT_MAX;

    if(dp[i][j] != -1) return dp[i][j];

    int down=f(i+1,j,grid),right=f(i,j+1,grid);
    int req=min(down,right)-grid[i][j];
    return dp[i][j]=(req <= 0) ? 1 : req;
}

int main(){
    vector<vector<int>>dungeon={{0,-3},{-10,0}};
    int m=dungeon.size();
    int n=dungeon[0].size();
    vector<vector<int>>dp(m,vector<int>(n));
    dp[m-1][n-1]=(dungeon[m-1][n-1] < 0) ? abs(dungeon[m-1][n-1])+1 : 1;
    
    // fill n-1th column
    for(int row=m-2;row>=0;row--){
        int req=dp[row+1][n-1]-dungeon[row][n-1];
        if(req <= 0) dp[row][n-1]=1;
        else dp[row][n-1]=req;
    }
    // fill m-1th row
    for(int col=n-2;col>=0;col--){
        int req=dp[m-1][col+1]-dungeon[m-1][col];
        if(req <= 0) dp[m-1][col]=1;
        else dp[m-1][col]=req;
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            int down=dp[i+1][j],right=dp[i][j+1];
            int req=min(down,right)-dungeon[i][j];
            dp[i][j]=(req <= 0) ? 1 : req;
        }
    }
    for(auto& row : dp){
        for(int x :row) cout<<x<<" ";
        cout<<endl;
    }
}