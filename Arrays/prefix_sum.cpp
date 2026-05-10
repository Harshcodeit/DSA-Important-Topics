#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int>&nums){
    for(int num:nums) cout<<num<<" ";
    cout<<endl;
}
void printGrid(vector<vector<int>>&grid){
    for(auto& row : grid){
        for(int x: row)cout<<x<<" ";
        cout<<endl;
    }
}
vector<int> prefixSum1D(vector<int>&nums){
    vector<int>ans(nums.size(),0);
    for(int i=0;i<nums.size();i++){
        if(i>0) ans[i]+=ans[i-1];
        ans[i]+=nums[i];
    }
    return ans;
}
vector<vector<int>>prefixSum2D(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>ans(m,vector<int>(n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i>0) ans[i][j]+=ans[i-1][j];
            if(j>0) ans[i][j]+=ans[i][j-1];
            if(i>0 && j>0) ans[i][j]-=ans[i-1][j-1];

            ans[i][j]+=grid[i][j];
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int>nums(N);
        for(int i=0;i<N;i++) cin>>nums[i];

        int m,n;
        cin>>m>>n;
        vector<vector<int>>grid(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) cin>>grid[i][j];
        }

        cout<<"Prefix sum of 1-D array : \n";
        vector<int>prefixSum=prefixSum1D(nums);
        printVec(prefixSum);

        cout<<"Prefix sum of 2-D array : \n";
        vector<vector<int>>gridSum=prefixSum2D(grid);
        printGrid(gridSum);
    }
}
/*
1
5
1 2 3 4 5
3 3
1 2 3
4 5 6 
7 8 9
*/