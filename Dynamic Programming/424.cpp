class Solution {
  public:
  
    int solve(int i, int j, string &s, vector<vector<int>> &dp) {
        
        // base case
        if(i >= s.length() || j >= s.length()) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int same = 0;
        int diff = 0;
        
        // same character, but must come from different indices
        if(s[i] == s[j] && i != j) {
            same = 1 + solve(i + 1, j + 1, s, dp);
        }
        else {
            // skip s[i]
            int skip_i = solve(i + 1, j, s, dp);
            
            // skip s[j]
            int skip_j = solve(i, j + 1, s, dp);
            
            diff = max(skip_i, skip_j);
        }
        
        return dp[i][j] = max(same, diff);
    }
  
    int longestRepSubseq(string &s) {
        
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solve(0, 0, s, dp);
    }
};