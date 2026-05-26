#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums={-13,11,7,-1};
    int x=2,k=2;
    int n=nums.size();
    multiset<int>left,right;
    int i=0,j=0;
    vector<vector<int>>subarr;
    while(j<n){
        if(left.size()<=right.size()) left.insert(nums[j]);
        else right.insert(nums[j]);
        int leftSize=left.size(),rightSize=right.size();
        while(leftSize>0 && rightSize>0){
            int maxLeft=*left.rbegin();
            int minRight=*right.begin();
            if(maxLeft>minRight){
                left.erase(left.find(maxLeft));
                right.erase(right.find(minRight));
                left.insert(minRight);
                right.insert(maxLeft);
                leftSize=left.size(),rightSize=right.size();
            }
            else break;
        }
        if((j-i+1) == x){
            int median=*left.rbegin();
            int moves=0;
            for(int k=i;k<=j;k++) moves+=abs(nums[k]-median);
            subarr.push_back({i,j,moves});
            if(left.find(nums[i])!=left.end()) left.erase(left.find(nums[i]));
            else right.erase(right.find(nums[i]));
            i++;
        }
        j++;
    }
    sort(subarr.begin(),subarr.end(),[](auto& a,auto&b){
        return a[2]<b[2];
    });
    for(auto&it : subarr){
        for(int k=it[0];k<=it[1];k++) cout<<nums[k]<<" ";
        cout<<it[2]<<endl;
    }

    int cnt=0;
    int s1=-1,e1=-1;
    long long ans=0ll;
    for(auto& it : subarr){
        if(it[0] > e1 || it[1] < s1){
            ans+=it[2];
            cnt++;
            s1=it[0],e1=it[1];
            for(int i=it[0];i<=it[1];i++) cout<<nums[i]<<" ";
            cout<<it[2]<<endl;
            if(cnt==k){
                cout<< ans<<endl;
                break;
            }
        }
    }
    if(cnt!=k){
        sort(subarr.begin(),subarr.end(),[](auto&a,auto&b){
            return a[1]<b[1];
        });
        ans=0;
        s1=-1,e1=-1;
        cnt=0;
        for(auto& it : subarr){
            if(it[0] > e1 || it[1] < s1){
                ans+=it[2];
                cnt++;
                s1=it[0],e1=it[1];
                for(int i=it[0];i<=it[1];i++) cout<<nums[i]<<" ";
                cout<<it[2]<<endl;
                if(cnt==k){
                    cout<< ans<<endl;
                    break;
                }
            }
        }
    }
    cout<<ans;
}