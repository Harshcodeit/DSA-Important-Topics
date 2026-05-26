/*
Reading Books
cses.fi/problemset/task/1631
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

long long f(vector<int>&t){
    long long sum=accumulate(t.begin(),t.end(),0ll);
    long long maxi=*max_element(t.begin(),t.end());

    if(maxi >= sum/2) return 2*maxi;
    else return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<int>t(n);
    for(int i=0;i<n;i++) cin>>t[i];

    cout<<f(t);
}

/*
3
2 3 8

3
2 3 4
*/