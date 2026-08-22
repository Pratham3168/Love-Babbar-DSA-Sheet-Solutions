// correct link : https://www.geeksforgeeks.org/problems/maximum-length-chain-of-pairs/1


class Solution {
  public:
  
    int solve(int i, vector<vector<int>> &arr, int prevIdx,vector<vector<int>> &dp){
        
        //base case
        if(i >= arr.size()){
            return 0;
        }
        
        if(dp[i][prevIdx+1] != -1){
            return dp[i][prevIdx+1];
        }
        
        //include
        int include =0;
        if(prevIdx == -1 || arr[i][0] > arr[prevIdx][1]){
            include = 1 + solve(i+1,arr,i,dp);
        }
        
        int exclude = solve(i+1,arr,prevIdx,dp);
        
        return dp[i][prevIdx+1] = max(include,exclude);
        
    }
    
  
    int maxChainLen(vector<vector<int>> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int ans = solve(0,arr,-1,dp);
        return ans;
    }
};
