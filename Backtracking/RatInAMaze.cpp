#include <bits/stdc++.h> 
using namespace std;

bool isSafe(int x,int y,vector<vector<bool>> &vis,vector<vector<int>> arr,int n){
    if((x>=0 && x<n) && (y>=0 && y<n) && (vis[x][y]!=1) && (arr[x][y]==1)){
        return true;
    }
}

void solve(int x,int y,vector<vector<int>> &arr,vector<string> &ans,
            string path,vector<vector<bool>> &vis,int n){
        
    //base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }

    // 4 Movements
    // Down,Left,Right,Up

    //Down
    if(isSafe(x+1,y,vis,arr,n)){
        vis[x][y]=1;
        solve(x+1,y,arr,ans,path+"D",vis,n);
        vis[x][y]=0;
    }

    //Left
    if(isSafe(x,y-1,vis,arr,n)){
        vis[x][y]=1;
        solve(x,y-1,arr,ans,path+"L",vis,n);
        vis[x][y]=0;
    }

    //Right
    if(isSafe(x,y+1,vis,arr,n)){
        vis[x][y]=1;
        solve(x,y+1,arr,ans,path+"R",vis,n);
        vis[x][y]=0;
    }

    //Up
    if(isSafe(x-1,y,vis,arr,n)){
        vis[x][y]=1;
        solve(x-1,y,arr,ans,path+"U",vis,n);
        vis[x][y]=0;
    }
    
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    string path="";
    if(arr[0][0]==0){
        return ans;
    }
    vector<vector<bool>> vis(n,vector<bool>(n,0));

    solve(0,0,arr,ans,path,vis,n);
    return ans;
}