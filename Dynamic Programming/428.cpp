class Solution {
  public:
  
    int solve(int i, vector<int> &arr,int lastIdx,vector<vector<int>> &dp){
        
        //base case
        if(i >= arr.size() ){
            return 0;
        }
        
        if( dp[i][lastIdx+1] != -1){
            return dp[i][lastIdx+1];
        }
        
        //include 
        int include = 0;
        if(lastIdx == -1 || arr[i] > arr[lastIdx]){
            include = arr[i] + solve(i+1,arr,i,dp);
        }
        
        //exclude 
        int exclude = solve(i+1,arr,lastIdx,dp);
        
        return dp[i][lastIdx+1] = max(include,exclude);
    }
  
  
    int maxSumIS(vector<int>& arr) {
        // code here
        
        vector<vector<int>> dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        int ans = solve(0,arr,-1,dp);
        return ans;
    }
};