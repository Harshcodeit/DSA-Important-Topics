#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>dp;
    Solution(int n){
        dp.resize(n+1,-1);
    }
    
    int climbStairs(int n) {
        if(n==0 ||n==1) return 1;
        return dp[n]= climbStairs(n-1) + climbStairs(n-2);
    }
};