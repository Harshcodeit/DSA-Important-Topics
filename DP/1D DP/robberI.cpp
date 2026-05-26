#include<bits/stdc++.h>
using namespace std;

int f(int n,vector<int>&nums,vector<int>&dp){
    if(n<=0) return 0;
    if(dp[n]!=-1) return dp[n];
    
    return dp[n]=max(
        nums[n-1]+f(n-2,nums,dp),
        f(n-1,nums,dp)
        );
}

int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n+1,-1);
    return f(n,nums,dp);
}