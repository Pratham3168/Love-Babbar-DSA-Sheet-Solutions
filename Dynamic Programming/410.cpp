class Solution {
  public:

    int solve(vector<int> &coins,int idx,int remaining, vector<vector<int>> &dp){
        
        //base case
        if(remaining == 0){
            return 1;
        }
        if(remaining < 0 || idx == coins.size()){
            return 0;
        }
        if(dp[idx][remaining] != -1){
            return dp[idx][remaining];
        }
        
        //take it
        int take = solve(coins,idx,remaining - coins[idx],dp);
        
        //dont take it'
        int notTake= solve(coins,idx+1,remaining,dp);
        
        dp[idx][remaining] = notTake + take;
        return dp[idx][remaining];
        
    }
  
    int count(vector<int>& coins, int sum) {
        // code here
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(coins,0,sum,dp);
    }
};