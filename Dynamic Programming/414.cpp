class Solution {
  public:
  
    int solve(int n,vector<int> &dp){
        
        //base case
        if(dp[n] != -1){
            return dp[n];
        }
        if(n<=1){
            return 1;
        }
        
        int ans =0;
        for(int i =0 ;i<n;i++){
            
            ans += solve(i,dp)*solve(n-1-i,dp);
            
        }
        
        dp[n] = ans;
        
        return dp[n];
        
    }
  
    // Function to find the nth catalan number.
    int findCatalan(int n) {
        // code here
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};