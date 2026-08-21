class Solution {
  public:
  
    int solve(int i, int j, string &s1, string& s2,vector<vector<int>> &dp){
        
        //base case
        if(i >= s1.length() || j >= s2.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int same =0;
        int del = 0;
    
        if(s1[i] == s2[j]){
            same = 1 + solve(i+1,j+1,s1,s2,dp);
        }
        else{
            
            //delete from s1
            int del_from_s1 = solve(i+1,j,s1,s2,dp);
            
            //delete from s2
            int del_from_s2 =solve(i,j+1,s1,s2,dp);
            
            del = max(del_from_s1,del_from_s2);
            
        }
        
        return dp[i][j] = max(same,del);
        
    }
  
    int lcs(string &s1, string &s2) {
        // code here
        int ans = 0;
        vector<vector<int>> dp(s1.length(),vector<int> (s2.length(),-1));
        return solve(0,0,s1,s2,dp);
        
        
    }
};
