class Solution {
  public:
  
    stack<int> st;

    void solve(vector<int> &arr,vector<int> &ans){
        
        for(int i = 0 ;i < arr.size();i++){
            
            if(!st.empty()){
                
                while(!st.empty() && arr[i] > arr[st.top()]){
                    ans[st.top()] = arr[i];
                    st.pop();
                }
                st.push(i);
                
            }
            else{
                st.push(i);
            }
            
        }
        
    }
  
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n,-1);
        solve(arr,ans);
        ans[n-1] = -1;
        return ans;

    }
};