#include<bits/stdc++.h>
using namespace std;

//returns medians of subarrays of size k
vector<int> f(vector<int>&nums,int k){
    int n=nums.size();
    int l=0,r=0;
    multiset<int>left,right;
    vector<int>medians;

    while(r<n){
        if(left.size() <= right.size()) left.insert(nums[r]);
        else right.insert(nums[r]);

        //balancing
        int leftSize=left.size(),rightSize=right.size();
        while(leftSize>0 && rightSize>0){
            int leftMax=*left.rbegin();
            int rightMin=*right.begin();

            if(leftMax > rightMin){
                left.insert(rightMin);
                right.insert(leftMax);

                left.erase(left.find(leftMax));
                right.erase(right.find(rightMin));

                leftSize=left.size();
                rightSize=right.size();
            }
            else break;
        }
        if(r-l+1 == k){
            medians.push_back(*left.rbegin());

            if(left.count(nums[l])) left.erase(left.find(nums[l]));
            else right.erase(right.find(nums[l]));

            l++;
        }
        r++;
    }
    return medians;
}

void printVec(vector<int>&nums){
    for(int num:nums) cout<<num<<" ";
    cout<<endl;
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
    vector<int>ans=f(nums,k);
    printVec(ans);
}

/*
9
5 -2 1 3 7 3 6 4 -1
5
*/