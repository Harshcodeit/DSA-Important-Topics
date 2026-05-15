#include<bits/stdc++.h>
using namespace std;

int search(vector<int>&nums,int x){
    int n=nums.size();
    int l=0,r=n-1;
    while(l<=r){
        int m=l+(r-l)/2;
    
        if(nums[m]==x) return m;

        if(nums[l]<=nums[m]){//left sorted
            if(nums[l]<=x && x<nums[m]) r=m-1;
            else l=m+1;
        }
        else{//right sorted
            if(nums[m]<x && x<=nums[r]) l=m+1;
            else r=m-1;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    int x;
    cin>>x;

    cout<<search(nums,x);
}
/*
6
3 4 5 5 1 2
5
*/