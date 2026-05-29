#include<bits/stdc++.h>
using namespace std;

/*
Partition s s.t each substring is a palindrome.Return all partitions
*/


bool isPal(int i,int j,string& s){
    if(i>=j) return true;
    if(s[i] != s[j]) return false;
    return isPal(i+1,j-1,s);
}
void f(int i,int n,string& s,vector<vector<string>>&ans,vector<string>&temp,vector<vector<bool>>&dp){
    if(i==n){
        ans.push_back(temp);
        return;
    }
    string t="";
    for(int k=i;k<n;k++){
        t+=s[k];
        if(dp[i][k]){ // isPal(i,k,s):instead of computing palindrome check in O(n)
            temp.push_back(t);
            f(k+1,n,s,ans,temp,dp);
            temp.pop_back();
        }
    }
}
//using backtracking,TC- O(n² * 2^n)
vector<vector<string>> partition(string s,vector<vector<bool>>&dp) {
    int n=s.size();
    vector<vector<string>>ans;
    vector<string>temp;
    f(0,n,s,ans,temp,dp);
    return ans;
}

//using memoization,dp[i][j]-whether substring [i...j] is palindrome or not
//TC- O(n * 2^n)
vector<vector<bool>> checkPal(string& s){
    int n=s.size();
    vector<vector<bool>>dp(n,vector<bool>(n,false));

    for(int i=0;i<n;i++) dp[i][i]=true;
    for(int L=2;L<=n;L++){
        for(int i=0;i+L-1<n;i++){
            int j=i+L-1;
            if(i+1 == j) dp[i][j]=(s[i] == s[j]);
            else dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
        }
    }
    return dp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        vector<vector<bool>>dp=checkPal(s);
        
        vector<vector<string>>ans=partition(s,dp);

        
    }
}