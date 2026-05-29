/*
printing lcs using bottom up dp
*/

#include<bits/stdc++.h>
using namespace std;

string print_lcs(string& s1,string& s2){
    int m=s1.size(),n=s2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1));

    for(int i=0;i<=m;i++) dp[i][0]=0;
    for(int j=0;j<=n;j++) dp[0][j]=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=m,j=n;
    string ans="";
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans=ans+s1[i-1];
            i--,j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(begin(ans),end(ans));
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;

        cout<<print_lcs(s1,s2);
    }
}

/*
TestCases:
Input-
1
abcdea beaf

Output-
bea
*/