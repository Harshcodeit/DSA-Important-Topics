/*
https://cses.fi/problemset/submit/1630
*/

#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

long long f(vector<pii>&tasks){
    sort(tasks.begin(),tasks.end(),[](auto& a,auto& b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    });

    long long ans=0ll;
    long long f=0ll;

    for(auto& task: tasks){
        f+=task.first;
        ans+=task.second-f;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<pii>tasks(n);
    for(int i=0;i<n;i++){
        int a,d;
        cin>>a>>d;
        tasks[i]={a,d};
    }
    cout<<f(tasks);
}