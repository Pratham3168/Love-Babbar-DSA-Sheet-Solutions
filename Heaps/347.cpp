class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        //max heap
        priority_queue<int> maxHeap;
        
        //min heap
        priority_queue<int,vector<int> , greater<int>> minHeap;
        
        vector<double> ans;
        
        for(int ele: arr){
            
            if (maxHeap.empty() || ele <= maxHeap.top()) {
                maxHeap.push(ele);
            } else {
                minHeap.push(ele);
            }
            
            while(maxHeap.size() > minHeap.size() + 1){
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
            }
            while(minHeap.size() > maxHeap.size() + 1){
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
            }
            
            double median = 0;
            
            if(maxHeap.size() == minHeap.size()){
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
            else{
                median = maxHeap.size() > minHeap.size() ? double(maxHeap.top()) : double(minHeap.top());
            }
            
            ans.push_back(median);
            
        }
        
        return ans;
    }
};
