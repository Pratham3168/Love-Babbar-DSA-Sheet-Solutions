class Solution {
  public:
  
    int solve(string& s1, string& s2,int i, int j,vector<vector<int>> &dp){
        
        if(i == s1.length()){
            return s2.length() - j;
        }
        if(j == s2.length()){
            return s1.length() -i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i] == s2[j]){
            return solve(s1,s2,i+1,j+1,dp);
        }
        else{
            //insert
            int insertAns = 1 + solve(s1,s2,i,j+1,dp);
            
            //remove
            int removeAns = 1 + solve(s1,s2,i+1,j,dp);
            
            //replace
            int replaceAns = 1 + solve(s1,s2,i+1,j+1,dp);
            ans = min(insertAns,min(removeAns,replaceAns));
        }
        
        return dp[i][j] = ans;
    }
  
    int editDistance(string& s1, string& s2) {
        // code here
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return solve(s1,s2,0,0,dp);
    }
};