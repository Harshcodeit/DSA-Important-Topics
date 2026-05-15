#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>ranges={0,3,3,2,2,4,2,1,5,1,0,1,2,3,0,3,1,1};
    int n=17;
    vector<vector<int>>intervals;
    for(int i=0;i<ranges.size();i++){
        if(ranges[i]==0) continue;
        intervals.push_back({max(0,i-ranges[i]),min(n,i+ranges[i])});
    }
    if(intervals.size()==0) return -1;
    
    sort(begin(intervals),end(intervals),[](auto&a,auto&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    });
    for(auto& i:intervals){
        for(int x : i) cout<<x<<" ";
        cout<<endl;
    }
    int s1=intervals[0][0],e1=intervals[0][1];
    if(s1!=0) return -1;
    if(e1==n) return 1;
    int ans=1;
    for(int i=1;i<intervals.size();i++){
        int end=intervals[i][1];
        while(i<intervals.size() && intervals[i][0]<=e1){
            if(intervals[i][1]==n) return 1+ans;
            end=max(end,intervals[i][1]);
            i++;
        }
        i--;
        e1=end;
        cout<<"end="<<end<<"\n";
        cout<<"i= "<<i<<"\n\n";
        ans++;//one optimal merge
        if(e1==n) cout<< ans;
    }
    cout<< -1;
}

/*
0 5 
0 4 
1 9 
1 5 
2 6 
3 13 
4 8 
6 8 
8 10 
10 16 
10 14 
10 12 
12 17 
15 17 
16 17 
*/