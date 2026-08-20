class Solution {
  public:
  
    int solve(int i, int j,vector<vector<int>>& a, vector<vector<int>>& t,vector<int>& x,
                vector<vector<int>> &dp){
        
        //base case
        if(j == a[0].size()-1){
            return a[i][j] + x[i];
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        //keep the assembly line
        int same = solve(i,j+1,a,t,x,dp);
        
        //change the assembly line
        int change =0;
        if(i == 0){
            change = t[i][j+1] + solve(i+1,j+1,a,t,x,dp);
        }
        else {
            change = t[i][j+1] + solve(i-1,j+1,a,t,x,dp);
        }
        
        return dp[i][j] = a[i][j] + min(same,change);
        
    }
  
  
    int carAssembly(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e,
                    vector<int>& x) {
        // code here
        int n = a.size();
        int m = a[0].size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        
        int ans = INT_MAX;
        for(int i =0; i< 2 ;i++){
            
            int result = e[i] + solve(i,0,a,t,x,dp);
            ans = min(result,ans);
            
        }
        
        return ans;
        
    }
};