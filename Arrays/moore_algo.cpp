#include<bits/stdc++.h>
using namespace std;

/*
used to find the majority element

naive approach : 2 nested loops-O(n^2)
better approach : hashmap-O(n) TC, O(n) SC
moore algo-O(n), O(1) SC

for count > floor[n/2] : only one majority element
for count > floor[n/3] : atmost two majority element
.
.
.
for count > [n/k] : atmost k-1 majority elements
*/

//for count > [n/2]
int moore_algo1(vector<int>&nums){
    //assume candidates and then verify
    int n=nums.size();
    int maj=-1,cnt=0;
    for(int i=0;i<n;i++){
        if(cnt==0){
            maj=nums[i];
            cnt++;
        }
        else if(nums[i]==maj) cnt++;
        else cnt--;
    }
    int tmp_cnt=0;
    for(int i=0;i<n;i++){
        if(nums[i]==maj) tmp_cnt++;
    }
    if(tmp_cnt>n/2) return maj;
    else return -1;
}

//for count > [n/3]
vector<int> moore_algo2(vector<int>&nums){
    int n=nums.size();
    int maj1=-1,c1=0;
    int maj2=-1,c2=0;

    for(int i=0;i<n;i++){
        if(nums[i]==maj1) c1++;
        else if(nums[i]==maj2) c2++;

        else if(c1==0) maj1=nums[i];
        else if(c2==0) maj2=nums[i];

        else{
            c1--;
            c2--;
        }
    }
    int tmp_c1=0,tmp_c2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==maj1) tmp_c1++;
        else if(nums[i]==maj2) tmp_c2++;
    }
    vector<int>ans;
    if(tmp_c1 > n/3) ans.push_back(maj1);
    if(tmp_c2 > n/3) ans.push_back(maj2);

    return ans;
}

//for count > [n/k]
vector<int> moore_algok(vector<int>&nums,int k){
    int n=nums.size();
    unordered_map<int,int>mp;//{maj,cnt}
    
    for(int num:nums){
        if(mp.count(num)) mp[num]++;
        else if(mp.size() < k-1) mp[num]=1;//new candidate
        else{
            for(auto& it:mp) it.second--;
        }
    }

    //verification
    unordered_map<int,int>freq;
    for(int num:nums){
        if(mp.count(num)) freq[num]++;
    }
    vector<int>ans;
    for(auto& it : freq){
        if(it.second > n/k) ans.push_back(it.first);
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];

        cout<<moore_algo1(nums)<<endl;

        vector<int>majority_el=moore_algok(nums,3);
        for(int el:majority_el) cout<<el<<" ";
        cout<<endl;
    }
}
/*
3
7
1 1 2 1 3 5 1
1
7
2
2 13

3
8
2 2 3 1 3 2 1 1
3
-5 3 -5
6
3 2 2 4 1 4
*/