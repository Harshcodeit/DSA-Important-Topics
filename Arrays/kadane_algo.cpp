#include<bits/stdc++.h>
using namespace std;

/*
used to find sub array sum
Brute force-O(n^2):all subarrays
*/

vector<int>kadane_algo(vector<int>&nums){
    int n=nums.size();
    long long maxi=LLONG_MIN,sum=0ll;
    int ansStart=-1,ansEnd=-1;
    int start=0;
    for(int i=0;i<n;i++){
        if(sum == 0) start=i;
        sum+=nums[i];
        if(sum > maxi){
            maxi=sum;
            ansStart=start;
            ansEnd=i;
        }
        if(sum < 0){
            sum=0;
        }
    }
    return {ansStart,ansEnd,(int)maxi};
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];

        vector<int>ans=kadane_algo(nums);
        cout<<"Subarray:";
        for(int i=ans[0];i<=ans[1];i++) cout<<nums[i]<<" ";
        cout<<"has a max sum of "<<ans[2]<<"\n\n";
    }
}
/*
3
7
2 3 -8 7 -1 2 3
2
-2 -4
5
5 4 1 7 8 
*/