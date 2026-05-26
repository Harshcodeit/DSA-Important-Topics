#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int>& nums) {
    int n=nums.size();
    int l=0,r=n-1;
    while(l<r){
        
        int m=l+(r-l)/2;
        if(nums[m]>nums[r]) l=m;
        else r=m-1;
    }
    return nums[l];
}
int findMin(vector<int>& nums) {
    int n=nums.size();
    int l=0,r=n-1;
    while(l<r){

        while(l<r && nums[l]==nums[l+1]) l++;
        while(r>l && nums[r]==nums[r-1]) r--;
        
        int m=l+(r-l)/2;
        if(nums[m]>nums[r]) l=m+1;
        else r=m;
    }
    return r;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];

    int i=findMin(nums);
    cout<<nums[i]<<endl;

    //in rotated array, max is just before min
    cout<<nums[(i-1+n)%n]<<endl;
}