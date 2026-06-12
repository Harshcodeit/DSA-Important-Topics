#include<bits/stdc++.h>
using namespace std;

// C(m+n-2,min(m-1,n-1))
int f(int m,int n){
    if(m==1 || n==1) return 1;
    int N=m+n-2;
    int r=min(m-1,n-1);
    long long res=1;
    for(int i=1;i<=r;i++){
        res=res*1ll*(N-r+i)/i;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    cin>>m>>n;

    cout<<f(m,n);
}