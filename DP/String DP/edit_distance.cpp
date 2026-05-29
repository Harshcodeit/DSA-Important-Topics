/*
Minimum operations to transform one string to another
*/

#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string& s1, string& s2,vector<vector<int>>&dp){
    if(i==0 && j==0) return 0;
    if(i==0 || j==0) return i+j;//if s2 exhausts,i deletes are needed . if s1 exhausts, i inserts are needed

    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i-1] == s2[j-1]) return dp[i][j]=f(i-1,j-1,s1,s2,dp);//match
    else{
        return dp[i][j]= min({
            1+f(i,j-1,s1,s2,dp),//insert
            1+f(i-1,j,s1,s2,dp),//delete
            1+f(i-1,j-1,s1,s2,dp)//replacement
        });
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        string word1,word2;
        cin>>word1>>word2;

        int m=word1.size(),n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        cout<<f(m,n,word1,word2,dp);
    }

}

/*
TestCases:
Input-
1
horse ros

Output-
3
*/