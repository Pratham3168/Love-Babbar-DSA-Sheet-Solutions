#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
        // Code here
        vector<vector<int>> ans;
        int n = grid.size();
        int m = grid[0].size();
        int len = word.length();
        int dx[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(word[0] != grid[i][j]) continue;
                
                for(int d = 0;d<8;d++){
                    
                   int x = i;
                   int y = j;
                   
                   int k = 0;
                   
                   while(k<len){
                       
                       if(x<0 || y<0 || x>=n || y>=m ){
                           break;
                       }
                       
                       if(grid[x][y] != word[k]){
                           break;
                       }
                       
                       x += dx[d];
                       y += dy[d];
                       k++;
                       
                   }
                   if(k == len){
                       ans.push_back({i,j});
                       break;
                   }
                   
                    
                }
                
            }
        }
        return ans;
    }
};