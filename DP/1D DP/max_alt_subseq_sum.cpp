#include<bits/stdc++.h>
using namespace std;
using LL=long long;
/*
Maximum alternating subsequence sum
*/

long long f(int i,bool parity,vector<int>&nums,vector<vector<long long>>&dp){
    if(i == nums.size()) return 0LL;
    if(dp[i][parity]!=-1) return dp[i][parity];

    LL ans=LLONG_MIN;
    //Either take or not take : If taken , parity is reversed else not

    LL take=f(i+1,!parity,nums,dp),notTake=f(i+1,parity,nums,dp);
    if(parity) ans=max(nums[i]+take,0+notTake);
    else ans=max(-nums[i]+take,-0+notTake);

    return dp[i][parity]=ans;
}

long long maxAlternatingSum(vector<int>& nums) {
    int n=nums.size();
    vector<vector<long long>>dp(n+1,vector<long long>(2,LLONG_MIN));
    
    dp[n][0]=0;
    dp[n][1]=0;

    for(int i=n-1;i>=0;i--){
        dp[i][1]=max(nums[i]+dp[i+1][0],dp[i+1][1]);
        dp[i][0]=max(-nums[i]+dp[i+1][1],dp[i+1][0]);
    }
    return dp[0][1];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];


}