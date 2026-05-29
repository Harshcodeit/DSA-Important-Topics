#include<bits/stdc++.h>
using namespace std;

/*
Either use interval dp where dp[i..j] tells length of lps and reconstruction is easier
Or use lcs on s and reverse of s. Since palindrome reversed is still present in string
*/

int longest_common_subsequence(int i,int j,string& s1,string& s2,vector<vector<int>>&dp){
    if(i==0 && j==0) return 0;
    if(i==0 || j==0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i-1] == s2[j-1]) return dp[i][j]=1+longest_common_subsequence(i-1,j-1,s1,s2,dp);
    else return dp[i][j]=max(longest_common_subsequence(i,j-1,s1,s2,dp),longest_common_subsequence(i-1,j,s1,s2,dp));
}
int lps(int i,int j,string& s,vector<vector<int>>&dp){
    if(i > j) return 0;
    if(i == j) return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==s[j]) return dp[i][j]=2+lps(i+1,j-1,s,dp);
    else return dp[i][j]=max(lps(i,j-1,s,dp),lps(i+1,j,s,dp));
}
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
    return dp[0][n-1];
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

        vector<vector<int>>t(n+1,vector<int>(n+1,-1));
        string temp=s;
        reverse(begin(temp),end(temp));
        cout<<"Using LCS "<<longest_common_subsequence(n,n,s,temp,t)<<endl;

        vector<vector<int>>dp(n,vector<int>(n,-1));
        cout<<"Using interval DP "<<lps(0,n-1,s,dp)<<endl;
        cout<<"Using bottom up "<<longest_palindromic_subseq(s)<<endl;
    }
}
/*
1
bbbab
*/