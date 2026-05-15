/*
Increasing Array
https://cses.fi/problemset/submit/1094/
*/

#include<bits/stdc++.h>
using namespace std;

long long f(vector<int>&nums){
    int n=nums.size();
    long long ans=0,maxi=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]<=maxi){
            ans+=(maxi-nums[i]);
        }
        else maxi=nums[i];
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    cout<<f(a);
}
