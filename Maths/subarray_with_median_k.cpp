#include<bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>& nums, int k) {
    int n=nums.size();
    int idx=-1;
    for(int i=0;i<n;i++){
        if(nums[i] > k) nums[i]=1;
        else if(nums[i] < k) nums[i]=-1;
        else{
            nums[i]=0;
            idx=i;
        }
    }
    unordered_map<int,int>mp;
    int bal=0;
    mp[0]=1;
    for(int i=idx+1;i<n;i++){
        bal+=nums[i];
        mp[bal]++;
    }
    int ans=0;
    bal=0;
    for(int i=idx-1;i>=0;i--){
        bal+=nums[i];
        if(mp.count(1-bal)) ans+=mp[1-bal];
        if(mp.count(-bal)) ans+=mp[-bal];
    }
    ans+=(mp[0]+mp[1]);
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    int k;
    cin>>k;
    cout<<countSubarrays(nums,k);
}

/*
5
3 2 1 4 5
4
*/