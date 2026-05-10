#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int>&nums){
    for(int num:nums) cout<<num<<" ";
    cout<<endl;
}
void printGrid(vector<vector<int>>&grid){
    for(auto& row : grid){
        for(int x: row)cout<<x<<" ";
        cout<<endl;
    }
}
void diffArr1D(vector<int>&nums,vector<vector<int>>&queries){
    int n=nums.size();
    vector<int>diff(n,0);
    for(auto query : queries) {
        int a=query[0],b=query[1],x=query[2];
        diff[a]+=x;
        if(b+1 < n) diff[b+1]-=x;
    }
    for(int i=1;i<n;i++) diff[i]+=diff[i-1];
    for(int i=0;i<n;i++) nums[i]+=diff[i];
}
void diffArr2D(vector<vector<int>>&grid,vector<vector<int>>&queries){
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>ans(m,vector<int>(n,0));

    for(auto query: queries){
        int r1=query[0],c1=query[1],r2=query[2],c2=query[3],x=query[4];
        ans[r1][c1]+=x;
        if(c2+1 < n) ans[r1][c2+1]-=x;
        if(r2+1 < m) ans[r2+1][c1]-=x;
        if(r2+1 < m && c2+1 < n) ans[r2+1][c2+1]+=x;
    }
    //row wise prefix sum
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++) ans[i][j]+=ans[i][j-1];
    }
    //column wise prefix sum
    for(int j=0;j<n;j++){
        for(int i=1;i<m;i++) ans[i][j]+=ans[i-1][j];
    }
    
    //update
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            grid[i][j]+=ans[i][j];
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int>nums(N);
        for(int i=0;i<N;i++) cin>>nums[i];

        int q1;
        cin>>q1;
        vector<vector<int>>queries1D(q1);
        for(int i=0;i<q1;i++){
            int a,b,x;
            cin>>a>>b>>x;
            queries1D[i]={a,b,x};
        }


        int m,n;
        cin>>m>>n;
        vector<vector<int>>grid(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) cin>>grid[i][j];
        }

        int q2;
        cin>>q2;
        //top left coord,bottom right cord and val
        vector<vector<int>>queries2D(q2);
        for(int i=0;i<q2;i++){
            int a,b,c,d,x;
            cin>>a>>b>>c>>d>>x;
            queries2D[i]={a,b,c,d,x};
        }

        cout<<"Updated 1-D array : \n";
        diffArr1D(nums,queries1D);
        printVec(nums);

        cout<<"Updated 2-D array : \n";
        diffArr2D(grid,queries2D);
        printGrid(grid);
    }
}
/*
1
5
1 2 3 4 5
1
1 3 100
3 3
1 2 3
4 5 6 
7 8 9
1
1 1 2 2 100
*/