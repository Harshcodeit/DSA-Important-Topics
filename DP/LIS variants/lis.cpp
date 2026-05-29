#include<bits/stdc++.h>
using namespace std;

//top down-O(n^2)
int f(int i,int prev,vector<int>&nums,vector<vector<int>>&dp){
    if(i==nums.size()+1) return 0;
    if(dp[i][prev]!=-1) return dp[i][prev];

    int skip=f(i+1,prev,nums,dp);
    int take=(prev==0 || nums[prev-1] < nums[i-1]) ? 1+f(i+1,i,nums,dp) : 0;

    return dp[i][prev]=max(take,skip);
}

//bottom up-O(n^2) and reconstruct
int f2(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,1);//len of lis ending at i
    vector<int>parent(n,-1);
    int lastIndex=-1;
    int maxLIS=1;

    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(nums[prev]<nums[i]){
                dp[i]=max(dp[i],1+dp[prev]);
                parent[i]=prev;
            }
        }
        
        if(dp[i]>maxLIS){
            maxLIS=dp[i];
            lastIndex=i;
        }
        
    }
    vector<int> ans;

    while(lastIndex != -1) {
        ans.push_back(nums[lastIndex]);
        lastIndex = parent[lastIndex];
    }

    reverse(ans.begin(), ans.end());

    return maxLIS;
}

//lazy/patience sorting sorting-O(nlogn)-For the same LIS length, keeping a smaller tail is always better.
int f3(vector<int>&nums){
    int n=nums.size();
    vector<int>temp;
    temp.push_back(nums[0]);
    int len=1;
    for(int i=1;i<n;i++){
        if(nums[i]> temp.back()){
            temp.push_back(nums[i]);
            len++;
        }
        else{
            int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[idx]=nums[i];
        }
    }
    return len;
}
//reconstruction in nlogn
vector<int> LIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> tail; // tail[len] = smallest possible tail value of an LIS of length (len+1)
    vector<int> tailIndex;//tailIndex[len] = index in nums[] of the smallest tail for LIS length (len+1)
    vector<int> parent(n, -1);//parent[i] = previous index in nums[] used to build the LIS ending at i

    for(int i = 0; i < n; i++) {
        int idx = lower_bound(tail.begin(), tail.end(), nums[i]) - tail.begin();
        // extend LIS
        if(idx == tail.size()) {
            tail.push_back(nums[i]);
            tailIndex.push_back(i);
        }
        // replace tail
        else {
            tail[idx] = nums[i];
            tailIndex[idx] = i;
        }
        // connect current element to previous LIS element
        if(idx > 0) {
            parent[i] = tailIndex[idx - 1];
        }
    }
    // reconstruct LIS
    vector<int> ans;
    int cur = tailIndex.back();
    while(cur != -1) {
        ans.push_back(nums[cur]);
        cur = parent[cur];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//count number of lis
int findNumberOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n,1);   //dp[i] stores length of LIS upto index i
    vector<int>cnt(n,1);  //cnt[i] stores no. of LIS with length dp[i] from nums[0...i]
    int maxi=1;
    for(int i=1;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(nums[prev]<nums[i] && 1+dp[prev] > dp[i]){
                dp[i]=1+dp[prev];
                cnt[i]=cnt[prev];
            }
            else if(nums[prev]<nums[i] && 1+dp[prev]==dp[i]){
                cnt[i]+=cnt[prev];
                
            }    
        }
        maxi=max(maxi,dp[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi) ans+=cnt[i];
    }
    return ans;
}

