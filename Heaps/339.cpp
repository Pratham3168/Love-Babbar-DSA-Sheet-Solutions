class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // code here
        // Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int ele: arr){
            if(pq.size() < k){
                pq.push(ele);
            }
            else if(ele > pq.top()){
                pq.pop();
                pq.push(ele);
            }
        }
        
        vector<int> ans(k);
        for(int i = k-1 ; i>=0 ; i--){
            ans[i] = pq.top();
            pq.pop();
        }
        
        return ans;
    }
};