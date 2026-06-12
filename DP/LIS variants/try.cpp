#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums={-3,4,3,2};
    int pivot=2;
    int n=nums.size();
    vector<pair<int,int>>temp;
    for(int i=0;i<n;i++) temp.push_back({nums[i],i});
    sort(begin(temp),end(temp));

    for(auto num : temp)cout<<num.first<<" "<<num.second<<endl;
    cout<<endl;


    int first=-1,last=-1;
    for(int i=0;i<n;i++){
        if(temp[i].first == pivot){
            first=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(temp[i].first == pivot){
            last=i;
            break;
        }
    }
    cout<<first<<" "<<last<<endl;
    
    sort(begin(temp),begin(temp)+first,[](auto& a,auto&b){
        return a.second < b.second;
    });
    sort(begin(temp)+last+1,end(temp),[](auto& a,auto& b){
        return a.second < b.second;
    });

    for(auto num : temp)cout<<num.first<<" "<<num.second<<endl;

    //first=3,last=3
    //0,3,2,1
    //-3,2,3,4
}