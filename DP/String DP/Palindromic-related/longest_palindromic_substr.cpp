#include<bits/stdc++.h>
using namespace std;

string longest_palindromic_substring(string& s){
    int n=s.size();
    vector<vector<bool>>dp(n,vector<bool>(n,false));

    int maxL=0,start=0;
    for(int L=1;L<=n;L++){
        for(int i=0;i+L-1<n;i++){
            int j=i+L-1;
            if(i==j) dp[i][j]=true;//singleton
            else if(i+1 == j) dp[i][j]=(s[i]==s[j]);
            else dp[i][j]=(s[i]==s[j]) && dp[i+1][j-1];

            if(dp[i][j]){
                maxL=L;
                start=i;
            }
        }
    }
    return s.substr(start,maxL);
}
/*
Manacher Algorithm is used to find longest palindromic substring in O(n) time
*/
string manacher_algo(string& s){
    string t="#";
    //transform string
    for(char ch:s){
        t+=ch;
        t+="#";
    }
    int n=t.size();
    int center=0,right=0;
    int maxLen=0,centerIdx=0;
    vector<int>p(n,0);//how far we can expand palindrome at i both sides

    for(int i=0;i<n;i++){
        //mirror accross prev center
        int mirror=2*center-i;

        //if inside previous palindrome
        if(i < right) p[i]=min(p[mirror],right-i);

        while(
            i+1+p[i] < n && i-1-p[i] >=0 && 
            t[i+1+p[i]]==t[i-1-p[i]]
        ){
            p[i]++;
        }
        if(i+p[i] > right){
            right=i+p[i];
            maxLen=p[i];
            centerIdx=i;
        }
    }
    int start=(centerIdx-maxLen)/2;
    return s.substr(start,maxLen);
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

        cout<<longest_palindromic_substring(s)<<endl;

        cout<<manacher_algo(s)<<endl;
    }
}