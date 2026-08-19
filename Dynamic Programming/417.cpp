class Solution {
  public:
  
    bool solve(int i, vector<int> &arr, int target,int sum,vector<vector<int>> &dp){
        
        //base case
        if(sum == target){
            return true;
        }
        if(sum > target){
            return false;
        }
        if(i >= arr.size()){
            return false;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        
        //take
        bool take = solve(i+1,arr,target,sum+arr[i],dp);
        
        //not take
        int not_take = solve(i+1,arr,target,sum,dp);
        
        
        return dp[i][sum] = take || not_take;
    }
  
    bool equalPartition(vector<int>& arr) {
        // code here
        
        int totalSum = 0;
        for(int ele: arr){
            totalSum += ele;
        }
        if(totalSum % 2 != 0){
            return false;
        }
        vector<vector<int>> dp(arr.size()+1,vector<int>(totalSum+1,-1));
        
        int target = totalSum/2;
        
        return solve(0,arr,target,0,dp);
        
    }
};