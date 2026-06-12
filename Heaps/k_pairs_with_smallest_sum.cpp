#include<bits/stdc++.h>
using namespace std;

/*
brute force -> generate all pairs and store top k smallest sums
TC:O(mnlogk)
*/

using pipii=pair<int,pair<int,int>>;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pipii,vector<pipii>,greater<pipii>>pq;
        int m=nums1.size(),n=nums2.size();
        vector<vector<int>>res;

        unordered_map<string,bool>mp;
        
        pq.push({nums1[0]+nums2[0],{0,0}});
        mp["0-0"]=true;
        while(k-- && !pq.empty()){
            auto it =pq.top();
            pq.pop();
            int i=it.second.first,j=it.second.second;

            string s=to_string(i)+"-"+to_string(j);
            res.push_back({nums1[i],nums2[j]});
        
            if(i+1 < m){
                string s=to_string(i+1)+"-"+to_string(j);
                if(!mp.count(s)) {
                    pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                    mp[s]=true;
                }
            }
            if(j+1 < n){
                string s=to_string(i)+"-"+to_string(j+1);
                if(!mp.count(s)){
                    pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                    mp[s]=true;
                }
            }
        }
        return res;
    }
};