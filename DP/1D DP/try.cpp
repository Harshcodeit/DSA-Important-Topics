#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums={0,4,2,1,0,-1,-3};
    int n=nums.size();
    vector<int>prefix(n,INT_MAX),suffix(n,INT_MIN);
    prefix[0]=nums[0];
    suffix[n-1]=nums[n-1];
    for(int i=1;i<n-1;i++){
        prefix[i]=min(nums[i],prefix[i-1]);
        suffix[n-1-i]=max(nums[n-1-i],suffix[n-i]);
    }
    if(n > 2){
        prefix[n-1]=min(nums[n-1],prefix[n-2]);
        suffix[0]=max(nums[0],nums[1]);
    }

    for(int x : prefix) cout<<x<<" ";
    cout<<endl;
    for(int x : nums) cout<<x<<" ";
    cout<<endl;
    for(int x : suffix) cout<<x<<" ";
    cout<<endl;

    for(int i=1;i<n-1;i++){
        if(nums[i] > prefix[i-1] && nums[i] < suffix[i+1]) cout<<"Yes\n";
        cout<<"Prefix = "<<prefix[i-1]<<" num = "<<nums[i]<<" Suffix = "<<suffix[i+1]<<endl;
    }
}