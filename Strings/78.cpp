// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    int solve(int i,int j,int idx, vector<vector<char>> &mat, string target,int size,int n,int m){
        
        int found = 0;
        
        if(i>=0 && j>=0 && j<m && i<n && target[idx] == mat[i][j]){
            char temp = target[idx];
            mat[i][j]= 0;
            idx++;
            if(idx == size){
                found =1;
            }
            else{
                found += solve(i+1,j,idx,mat,target,size,n,m);
                found += solve(i-1,j,idx,mat,target,size,n,m);
                found += solve(i,j+1,idx,mat,target,size,n,m);
                found += solve(i,j-1,idx,mat,target,size,n,m);
            }
            mat[i][j]=temp;
        }
        return found;
    }
  
    int findOccurrence(vector<vector<char> > &mat, string target) {
        
        int n=mat.size();
        int m=mat[0].size();
        int size = target.length();
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j =0 ;j<m;j++){
                ans += solve(i,j,0,mat,target,size,n,m);
            }
        }
        return ans;
        
    }
};