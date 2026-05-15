#include<bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<int> &start, vector<int> &end) {
    // code here
    map<int,int>events;
    int n=start.size();
    for(int i=0;i<n;i++){
        events[start[i]]++;
        events[end[i]]--;
    }
    int maxOverlaps=0,curOverlaps=0;
    for(auto& event : events){
        curOverlaps+=event.second;
        
        maxOverlaps=max(maxOverlaps,curOverlaps);
    }
    
    return maxOverlaps;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>start(n),end(n);
        for(int i=0;i<n;i++) cin>>start[i];
        for(int i=0;i<n;i++) cin>>end[i];

        cout<<minMeetingRooms(start,end)<<endl;
    }
}
/*
1
3
2 9 6 
4 12 10
*/


#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

class SegmentTree{
    public:
    int n;
    vector<pii>segTree;//store {min,max} in range l to r
    
    SegmentTree(vector<int>&nums){
        n=nums.size();
        
        segTree.resize(4*n,{INT_MAX,INT_MIN});
        buildTree(0,0,n-1,nums);
    }
    
    void buildTree(int i,int l,int r,vector<int>&nums){
        if(l==r){
            segTree[i]={nums[l],nums[l]};
            return;
        }
        int mid=l+(r-l)/2;
        buildTree(2*i+1,l,mid,nums);
        buildTree(2*i+2,mid+1,r,nums);
        
        segTree[i].first=min(segTree[2*i+1].first,segTree[2*i+2].first);
        segTree[i].second=max(segTree[2*i+1].second,segTree[2*i+2].second);
    }
    //query 1 
    void updateQuery(int idx,int v,int i,int l,int r){
        if(l==r){
            segTree[i]={v,v};
            return;
        }
        int mid=l+(r-l)/2;
        if(idx <= mid) updateQuery(idx,v,2*i+1,l,mid);
        else updateQuery(idx,v,2*i+2,mid+1,r);
        
        segTree[i].first=min(segTree[2*i+1].first,segTree[2*i+2].first);
        segTree[i].second=max(segTree[2*i+1].second,segTree[2*i+2].second);
    }
    //query 2
    pii min_max(int start,int end,int i,int l,int r){
        if(start>r || end <l) return {INT_MAX,INT_MIN};
        if(l>=start && r<=end) return segTree[i];
        
        int mid=l+(r-l)/2;
        pii left=min_max(start,end,2*i+1,l,mid);
        pii right=min_max(start,end,2*i+2,mid+1,r);
        
        return {
            min(left.first,right.first),
            max(left.second,right.second);
        };
    }
    int rangeQuery(int start,int end,int i,int l,int r){
        if(end-start+1 == 1) return segTree[i].first;//base case
    }
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        
        vector<vector<int>>queries(q);
        for(int i=0;i<q;i++){
            int a,b,c;
            cin>>a>>b>>c;
            queries[i]={a,b,c};
        }
        
        SegmentTree tree(a);
        
        for(vector<int>&query : queries){
            if(query[0]==1){
                tree.updateQuery(query[1],query[2],0,0,n-1);
            }
            else{
                cout<<tree.rangeQuery(query[1],query[2],0,0,n-1)<<endl;
            }
        }
    }
}
