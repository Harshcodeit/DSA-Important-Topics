#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>>t(n,vector<bool>(n,false));//t[i][j] is true if s[i...j] is a palindrome
        for(int i=0;i<n;i++) t[i][i]=true;

        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(i+1 == j) t[i][j]=(s[i] == s[j]);
                else t[i][j]=(s[i] == s[j] && t[i+1][j-1]);
            }
        }
        vector<int>dp(n+1,0);
        dp[n]=0;//no cut required

        for(int i=n-1;i>=0;i--){
            int ans=INT_MAX;
            for(int j=i;j<n;j++){
                if(t[i][j]){
                    ans=min(ans,1+dp[j+1]);
                }
            }
            dp[i]=ans;
        }
        return dp[0]-1;
    }
};