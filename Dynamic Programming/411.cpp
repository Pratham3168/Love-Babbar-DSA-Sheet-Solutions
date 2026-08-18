class Solution {
  public:
    int ans;
  
    int solve(int W, vector<int> &val, vector<int> &wt,int idx, int weight,vector<vector<int>>& dp){
        
        //base case
        if(idx == val.size() || weight == W){
            return 0;
        }
        
        if(dp[idx][weight] != -1)
            return dp[idx][weight];
        
        
        // Take
        int take = 0;

        if(weight + wt[idx] <= W)
            take = val[idx] + solve(W, val, wt, idx + 1, weight + wt[idx],dp);
        
        //dont take the item
        int notTake = solve(W,val,wt,idx+1,weight,dp);
        
        return dp[idx][weight] = max(take,notTake);
        
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        ans = INT_MIN;
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solve(W, val, wt , 0,0,dp);
    }
};