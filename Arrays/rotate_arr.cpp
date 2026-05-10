#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int>&nums){
    for(int num:nums) cout<<num<<" ";
    cout<<endl;
}
void rotateLeft(vector<int>&nums,int k){
    int n=nums.size();
    k%=n;
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+n-k);
    reverse(nums.begin()+n-k,nums.end());
}
void rotateRight(vector<int>&nums,int k){
    int n=nums.size();
    k%=n;
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];

        int k;
        cin>>k;

        cout<<"Array before rotation\n";
        printVec(nums);

        cout<<"Array after left rotation : ";
        rotateLeft(nums,k);
        printVec(nums);

        cout<<"Array after right rotation : ";
        rotateRight(nums,k);
        printVec(nums);

        /* ---STL--- */
        rotate(nums.begin(),nums.begin()+k,nums.end());
        cout<<"Array after left rotation : ";
        printVec(nums);

        cout<<"Array after right rotation : ";
        rotate(nums.begin(),nums.begin()-k,nums.end());
        printVec(nums);
    }
}
/*
1
6
1 2 3 4 5 6
2
*/