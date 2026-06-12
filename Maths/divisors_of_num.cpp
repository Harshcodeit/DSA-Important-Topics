#include<bits/stdc++.h>
using namespace std;

vector<int> get_divisors(int n){
    vector<int>res,t;
    for(int num=sqrt(n);num>=1;num--){
        if(n % num == 0){
            res.push_back(num);
            if(n/num != num) t.push_back(n/num);
        }
    }
    reverse(begin(res),end(res));
    for(int d : t) res.push_back(d);

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>ans=get_divisors(n);
        for(int x : ans) cout<<x<<" ";
        cout<<endl;
    }
}