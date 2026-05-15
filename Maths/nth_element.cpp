#include<bits/stdc++.h>
using namespace std;

/*
nth_element(begin_itr,kth_idx,end_itr) 
uses quickselects to arrange kth element w/o sorting
elements precedeing are smaller and succeding are greater
*/

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];

    int k;
    cin>>k;

    //get kth smallest element in average O(n) time
    nth_element(begin(nums),begin(nums)+k-1,end(nums));

    cout<<nums[k-1]<<endl;

    //get kth largest element in average O(n) time
    nth_element(begin(nums),begin(nums)+k-1,end(nums),greater<int>());
    cout<<nums[k-1]<<endl;
}
/*
5
3 4 5 1 2
2
*/