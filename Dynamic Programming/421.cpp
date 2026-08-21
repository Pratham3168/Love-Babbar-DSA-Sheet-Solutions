class Solution {
  public:
  
    int solve(int i,int previousCount,int n,int k,vector<vector<int>> &dp){
        
        //base case
        if(i > n){
            return 1;
        }
        if(dp[i][previousCount] != -1){
            return dp[i][previousCount];
        }
        
        //same color
        int same = 0;
        if(previousCount < 2){
            same = solve(i+1,previousCount+1,n,k,dp);
        }
        
        //different color
        int diff = (k-1)*solve(i+1,1,n,k,dp);
        
        return dp[i][previousCount] = same + diff;
        
        
    }
  
    int countWays(int n, int k) {
        // code here
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        return k*solve(2,1,n,k,dp);
    }
};