/*
longest common subsequence
hirschberg algorithm can compute lcs in O(n) time
*/

#include<bits/stdc++.h>
using namespace std;

int longest_common_subsequence(int i,int j,string& s1,string& s2,vector<vector<int>>&dp){
    if(i==0 && j==0) return 0;
    if(i==0 || j==0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i-1] == s2[j-1]) return dp[i][j]=1+longest_common_subsequence(i-1,j-1,s1,s2,dp);
    else return dp[i][j]=max(longest_common_subsequence(i,j-1,s1,s2,dp),longest_common_subsequence(i-1,j,s1,s2,dp));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;

        int m=s1.size(),n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        cout<<longest_common_subsequence(m,n,s1,s2,dp);
    }
}

/*
TestCases:
Input-
1
abcdea beaf

Output-
3
*/