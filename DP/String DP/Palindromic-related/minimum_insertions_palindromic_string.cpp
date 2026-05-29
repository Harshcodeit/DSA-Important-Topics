#include<bits/stdc++.h>
using namespace std;

//using interval dp
int minimum_operations(int i,int j,string& s,vector<vector<int>>&dp){
    if(i >= j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==s[j]) return dp[i][j]=0+minimum_operations(i+1,j-1,s,dp);
    else return dp[i][j]=1+min(minimum_operations(i,j-1,s,dp),minimum_operations(i+1,j,s,dp));
}

//using lps
int longest_palindromic_subseq(string& s){
    int n=s.size();
    vector<vector<int>>dp(n,vector<int>(n,0));//length of lps in s[i...j]
    
    for(int i=0;i<n;i++) dp[i][i]=1;
    for(int L=2;L<=n;L++){
        for(int i=0;i+L-1<n;i++){
            int j=i+L-1;
            if(s[i]==s[j]) dp[i][j]=2+dp[i+1][j-1];
            else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return n-dp[0][n-1];//insert for those not in lps
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
        cout<<"Using interval dp :"<<minimum_operations(0,n-1,s,dp)<<endl;
        cout<<"Using lps :"<<longest_palindromic_subseq(s)<<endl;
    }
}
/*
TestCase;
Input-

3
zzazz
mbadm
leetcode

Output-
0
2
5
*/