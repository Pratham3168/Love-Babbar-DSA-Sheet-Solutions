class Solution {
  public:
  
    int maxSteps = INT_MIN;
    int n;
    int m ;
    vector<vector<bool>> visited;
    
    void solve(int row, int col, vector<vector<int>> &mat, int tempSteps,int xd,int yd){
        
        //base case
        if(row == xd && col == yd){
            maxSteps = max(maxSteps,tempSteps);
            return;
        }
        
        visited[row][col] = true;
        
        //up
        if(row > 0 && mat[row-1][col] != 0 && !visited[row-1][col]){
            solve(row-1,col,mat,tempSteps + 1,xd,yd);
        }
        
        //down
        if(row < n-1 && mat[row+1][col] !=0 && !visited[row+1][col]){
            solve(row+1,col,mat,tempSteps+1,xd,yd);
        }
        
        //left
        if(col > 0 && mat[row][col-1] !=0 && !visited[row][col-1]){
            solve(row,col-1,mat,tempSteps+1,xd,yd);
        }
        
        //right
        if(col < m-1 && mat[row][col+1] !=0 && !visited[row][col+1]){
            solve(row,col+1,mat,tempSteps+1,xd,yd);
        }
        
        visited[row][col] = false;
        
    }
  
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd) {
        // code here
        if(matrix[xs][ys] == 0){
            return -1;
        }
        n = matrix.size();
        m = matrix[0].size();
        visited = vector<vector<bool>>(n,vector<bool>(m,false));
        solve(xs,ys,matrix,0,xd,yd);
        
        if(maxSteps == INT_MIN){
            return -1;
        }
        
        return maxSteps;
        
    }
};