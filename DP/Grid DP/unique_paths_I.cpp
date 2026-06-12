#include<bits/stdc++.h>
using namespace std;

int f(int i,int j){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;

    return f(i-1,j)+f(i,j-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    cin>>m>>n;

    cout<<f(m-1,n-1);
}