/*
Ferris Wheel
https://cses.fi/problemset/submit/1090/
*/

#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&weights,int x){
    int gondolas=0;
    sort(weights.begin(),weights.end());

    int n=weights.size();
    int l=0,r=n-1;
    while(l<=r){
        if(weights[l]+weights[r] <= x) l++;
        gondolas++;
        r--;
        
    }
    if(l==r) gondolas++;
    return gondolas;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n>>x;
    vector<int>w(n);
    for(int i=0;i<n;i++) cin>>w[i];

    cout<<f(w,x);
}