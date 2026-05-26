#include<bits/stdc++.h>
using namespace std;
using ll=long long;

//Optimized solution using suffix arr
//TC:O(nmk)
class Solution {
public:
    int mod=1e9+7;
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(n+1,vector<ll>(m+1,0)));
        vector<vector<vector<ll>>>suffix(n+1,vector<vector<ll>>(n+1,vector<ll>(m+1,0)));

        suffix[n][k][m]=1;
        for(int maxi=m;maxi>=0;maxi--){
            dp[n][k][maxi]=1;
            if(maxi < m) suffix[n][k][maxi]=1+suffix[n][k][maxi+1];
        }

        for(int i=n-1;i>=0;i--){
            for(int cost=0;cost<n;cost++){
                for(int maxi=m;maxi>=0;maxi--){

                    ll ans=(1ll*(dp[i+1][cost][maxi]%mod)*maxi)%mod;
                    if(maxi < m) ans=(ans+suffix[i+1][cost+1][maxi+1])%mod; 

                    dp[i][cost][maxi]=ans;
                    suffix[i][cost][maxi]=dp[i][cost][maxi];
                    if(maxi < m) suffix[i][cost][maxi]+=suffix[i][cost][maxi+1];
                }
            }
        }
        return dp[0][0][0];//
    }
};