#include<bits/stdc++.h>
using namespace std;

/*
Used to sort an arr of 0s and 1s in O(n) time

Naive Approach:Count 0s,1s and 2s and fill-O(2n)

Optimal Approach:Hoare partition algorithm:O(n)
*/
void printVec(vector<int>&nums){
    for(int num:nums)cout<<num<<" ";
    cout<<endl;
}
void hoare_partition(vector<int>&nums){
    int n=nums.size();
    int l=0,r=n-1;
    while(l<r){
        if(nums[l]==0) l++;
        else if(nums[r]==1) r--;
        else{
            if(l<r) swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];

        cout<<"Array before sorting:\n";
        printVec(nums);

        hoare_partition(nums);

        cout<<"Array after sorting:\n";
        printVec(nums);
    }
}
/*
4
10
0 1 0 1 0 0 1 1 1 0
3
0 1 0
2
1 1 
1 
0
*/