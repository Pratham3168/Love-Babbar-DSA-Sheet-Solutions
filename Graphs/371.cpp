class Solution {
  public:
  
    void dfs(int x,int y,vector<vector<char>>& grid,vector<vector<bool>> &visited,
                int dx[], int dy[],int n,int m)
    {
        
        visited[x][y] = true;
        
        for(int k =0; k < 8; k++){
            
            int newX = x + dx[k];
            int newY = y + dy[k];
            
            if(newX >= 0 && newX < n && newY >=0 && newY < m){
                if( grid[newX][newY] == 'L' &&  !visited[newX][newY]){
                    dfs(newX,newY,grid,visited,dx,dy,n,m);
                }
            }
            
        }
        
    }
  
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1,  0,  1,-1, 1,-1, 0, 1};
        
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        
        
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(grid[i][j] == 'L' && !visited[i][j]){
                    count++;
                    dfs(i,j,grid,visited,dx,dy,n,m);
                }
                
            }
        }
        
        return count;
    }
};