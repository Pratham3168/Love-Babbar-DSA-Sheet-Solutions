class Solution {
  public:
  
    int solve(int n, int r,vector<vector<int>> &dp){
        
        if(dp[n][r]!=-1){
            return dp[n][r];
        }
        if(r==0 || r==n){
            return 1;
        }
        if(r>n){
            return 0;
        }
        
        //take it
        int take = solve(n-1,r-1,dp);
        
        //dont take
        int notTake = solve(n-1,r,dp);
        
        return dp[n][r] = take+notTake;
        
    }
  
    int nCr(int n, int r) {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
        return solve(n,r,dp);
    }
};