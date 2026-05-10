#include<bits/stdc++.h>
using namespace std;

/*
Used to sort an arr with 3 elements in O(n) time

Naive Approach:Sorting-O(nlogn)

Better Approach:Count 0s,1s and 2s and fill-O(2n)

Optimal Approach:Dutch flag algorithm:O(n)
*/
void printVec(vector<int>&nums){
    for(int num:nums)cout<<num<<" ";
    cout<<endl;
}
void dutch_sort(vector<int>&nums){
    int n=nums.size();
    int lo=0,mid=0,hi=n-1;
    /*
    arr[0...lo-1]=all 0s
    arr[lo...mid-1]=all 1s
    arr[mid...hi-1]=unprocessed elements
    arr[hi...n-1]=all 0s

    lo=index where 0 should be placed
    mid=index being checked
    high=index where 2 should be placed
    */
    while(mid<=hi){
        if(nums[mid]==0){
            swap(nums[lo],nums[mid]);
            lo++;
            mid++;
        }
        else if(nums[mid]==1) mid++;
        else{
            swap(nums[mid],nums[hi]);
            hi--;
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

        dutch_sort(nums);

        cout<<"Array after sorting:\n";
        printVec(nums);
    }
}
/*
2
6
0 1 2 0 1 2
12
0 1 1 0 1 2 1 2 0 0 0 1
*/