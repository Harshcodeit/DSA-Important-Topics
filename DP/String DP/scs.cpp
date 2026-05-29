/*
Shortest Common Supersequence
*/

#include<bits/stdc++.h>
using namespace std;

int scs(int i,int j,string& s1,string &s2,vector<vector<int>>&dp){
    if(i==0 && j==0) return 0;
    else if(i==0) return j;
    else if(j==0) return i;

    if(s1[i-1] == s2[j-1]) return dp[i][j]=1+scs(i-1,j-1,s1,s2,dp);
    else return dp[i][j]=1+min(scs(i,j-1,s1,s2,dp),scs(i-1,j,s1,s2,dp));
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
        cout<<scs(m,n,s1,s2,dp)<<endl;
    }
}

/*
Input-
2
abcd xycd
efgh jghi

Output-
6
6
*/