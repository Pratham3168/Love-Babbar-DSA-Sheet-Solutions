/*You are required to complete this method */
class Solution {
  public:
  
    void solve(bool &ans, int n, int k , 
                int currSum,int subsetCnt, vector<int> &arr,
                int target, vector<bool>&visited,int startIndex){
        
        //base case
        if(subsetCnt == k-1){
            ans = true;
            return;
        }
        
        if(currSum > target){
            return;
        }
        
        if(currSum == target){
            return solve(ans,n,k,0,subsetCnt+1,arr,target,visited,0);
        }
        
        for(int i = startIndex;i<n;i++){
            if(!visited[i]){
                if(currSum + arr[i] > target)continue;
                
                visited[i] = true;
                solve(ans,n,k,currSum + arr[i],subsetCnt,arr,target,visited,i+1);
                if(ans == true)return;
                visited[i] = false;
                
            }
        }
        
    }
  
    bool isKPartitionPossible(vector<int> &arr, int k) {
        // Your code here
        int n =arr.size();
        if(k > n){
            return false;
        }
        if(k ==1 ){
            return true;
        }
        int sum = 0;
        for(int ele:arr){
            sum += ele;
        }
        if(sum%k != 0){
            return false;
        }
        
        int target = sum/k;
        vector<bool> visited(n,false);
        bool ans = false;
        solve(ans,n,k,0,0,arr,target,visited,0);
        return ans;
        
    }
};