/*
leetcode problem 2926
sum of largest LIS ending at index i
*/

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n=nums.size();
        // int maxi=*max_element(nums.begin(),nums.end());
        // if(maxi <= 0) return maxi;

        map<ll,ll>mp;//{nums[i]-i,max sum of LIS upto i}
        ll res=LLONG_MIN;

        for(int i=0;i<n;i++){
            ll key=nums[i]-i;
            
            ll sum=nums[i];
            auto it=mp.upper_bound(key);
            if(it != mp.begin()){
                it--;
                sum+=it->second;
            }
            mp[key]=max(mp[key],sum);

            it=mp.upper_bound(key);
            while(it!=mp.end() && it->second <= sum) mp.erase(it++);

            res=max(res,sum);
        }
        return res;
    }
};