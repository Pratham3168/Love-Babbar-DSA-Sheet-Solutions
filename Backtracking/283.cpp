class Solution {
  public:
  
    vector<int> dx = {2,2,-2,-2,1,1,-1,-1};
    vector<int> dy = {1,-1,1,-1,2,-2,2,-2};
    int maxSteps;
    int n;
    
    
    bool solve(int x,int y, int step,vector<vector<int>> &board){
        //base case
        if(step == maxSteps -1){
            return true;
        }
        
        for(int k = 0 ; k < 8; k++){
            int newX = x + dx[k];
            int newY = y + dy[k];
            
            if((newX >= 0 && newY >= 0 && newX < n && newY < n) && board[newX][newY] == -1){
                
                board[newX][newY] = step + 1;
                
                if(solve(newX,newY,step+1,board)){
                    return true;
                }
                
                board[newX][newY] = -1;
                
            }
        }
        
        return false;
    }
  
    vector<vector<int>> knightTour(int N) {
        // code here
        n = N;
        maxSteps = n*n; 
        vector<vector<int>> board(n,vector<int>(n,-1));
        board[0][0] = 0;

        bool ok = solve(0,0,0,board);
        if(!ok){
            return {};
        }
        return board;
        
    }
};