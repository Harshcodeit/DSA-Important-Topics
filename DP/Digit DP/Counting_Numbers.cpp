#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll dp[20][2][11][2];


ll f(string&s,int i,bool tight,int prev,bool lz){
    if(i == s.size()) return 1;

    if(dp[i][tight][prev][lz] != -1) return dp[i][tight][prev][lz];

    int lb=0;
    int ub=(tight) ? (s[i]-'0') : 9;

    ll ans=0;
    for(int digit=lb;digit<=ub;digit++){
        if(digit == prev && !lz) continue;
        ans+=f(s,i+1,(tight && digit == ub),digit,(lz && digit == 0));
    }
    return dp[i][tight][prev][lz]=ans;
}

ll solve(ll a,ll b){

    string l=to_string(a-1);
    memset(dp,-1,sizeof(dp));
    ll ans_l=f(l,0,1,10,1);

    memset(dp,-1,sizeof(dp));
    string r=to_string(b);
    ll ans_r=f(r,0,1,10,1);

    return ans_r-ans_l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a,b;
    cin>>a>>b;

    cout<<solve(a,b);
}