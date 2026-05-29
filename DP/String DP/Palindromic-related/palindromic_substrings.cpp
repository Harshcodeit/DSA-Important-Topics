#include<bits/stdc++.h>
using namespace std;

//---recursion and memoization--//
/*
generate all substrings and check if each substring is a valid palindrome or not 
TC:O(n^2 * n)
After memoization,Tc:O(n^2)
*/

bool isPal(int i,int j,string& s,vector<vector<int>>&dp){
    if(i > j) return true;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i] != s[j]) return dp[i][j]= false;
    return dp[i][j]=isPal(i+1,j-1,s,dp);
}
int f(int i,int n,string& s,vector<vector<int>>&dp){
    if(i==n) return 0;

    int ans=0;
    for(int j=i;j<n;j++){
        if(isPal(i,j,s,dp)) ans++;
    }
    return ans+f(i+1,n,s,dp);
}

//---bottom up---//
int palindromic_substrings(string& s){
    int n=s.size();
    vector<vector<bool>>dp(n,vector<bool>(n,false));

    int count=0;
    for(int L=1;L<=n;L++){
        for(int i=0;i+L-1<n;i++){
            int j=i+L-1;
            if(i==j) dp[i][j]=true;//singleton
            else if(i+1 == j) dp[i][j]=(s[i]==s[j]);
            else dp[i][j]=(s[i]==s[j]) && dp[i+1][j-1];

            if(dp[i][j]) count++;
        }
    }
    return count;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        cout<<f(0,n,s,dp)<<endl;

        cout<<palindromic_substrings(s)<<endl;
    }
}
/*
TestCases:
Input-
2
abc
aaa

Output-
3
6
*/