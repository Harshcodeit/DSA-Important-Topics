//Longest divisible subset-variant of LIS , only condition is changed
#include<bits/stdc++.h>
using namespace std;


//bottom up
using ll=long long;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>parent(n,-1),dp(n,1);
        int maxi=0,last=-1;

        sort(begin(nums),end(nums));

        for(int i=0;i<n;i++){
            parent[i]=i;
            for(int j=0;j<i;j++){
                if((nums[i] % nums[j] == 0) && 1+dp[j] > dp[i]){
                    dp[i]=1+dp[j];
                    parent[i]=j;
                }
            }
            if(dp[i] > maxi){
                maxi=dp[i];
                last=i;
            }
        }
        vector<int>ans;
        while(last != parent[last]){
            ans.push_back(nums[last]);
            last=parent[last];
        }
        ans.push_back(nums[last]);
        
        reverse(begin(ans),end(ans));
        return ans;
    }
};

//recursive sol
class Solution1 {
public:
    vector<int>ans,temp;
    int n;
    void f(int prev,int i,vector<int>&nums){
        if(i == n){
            if(temp.size() > ans.size()){
                ans=temp;
            }
            return;
        }
        if(prev == -1 || nums[i] % nums[prev] ==0){
            temp.push_back(nums[i]);
            f(i,i+1,nums);
            temp.pop_back();
        }
        f(prev,i+1,nums);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
        n=nums.size();
        f(-1,0,nums);

        return ans;
    }
};