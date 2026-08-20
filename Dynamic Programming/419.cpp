class Solution {
  public:
  
    int solve(int i, int j, vector<vector<int>>& mat,vector<vector<int>>& dp){
        
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int val = mat[i][j];
        
        //diagonal up-right
        int diag_up_right = val + solve(i-1,j+1,mat,dp);
        
        //right
        int right = val + solve(i,j+1,mat,dp);
        
        //diagonal down right
        int diag_down_right = val + solve(i+1,j+1,mat,dp);
        
        return dp[i][j] = max(diag_up_right,max(right,diag_down_right));
        
    }
  
  
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int ans = INT_MIN;
        int n = mat.size() ;
        int m = mat[0].size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
        for(int i =0; i< n ;i++){
            
            int result = solve(i,0,mat,dp);
            ans = max(result,ans);
            
        }
        
        return ans; 
        
    }
};