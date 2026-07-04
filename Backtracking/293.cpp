class Solution {
  public:
  
    string ans = "";
    
    void solve(vector<int>&nums,int k,int &bs){
        //base case
        if(k == 1){
            for(int ele : nums){
                ans += to_string(ele);
            }
            return;
        }
        
        int idx = (k-1)/bs;
        int k1 = k - (idx*bs);
        ans += to_string(nums[idx]);
        nums.erase(nums.begin() + idx);
        if(!nums.empty())
            bs = bs / nums.size();        
        solve(nums,k1,bs);
        
    }
  
    string kthPermutation(int n, int k) {
        // code here
        ans = "";
        vector<int> nums;
        for(int i = 1; i<= n; i++){
            nums.push_back(i);
        }
        
        int bs = 1;
        for(int i = 1;i<n ;i++){
            bs = bs*i;
        }
        
        solve(nums,k,bs);
        return ans;
    }
};