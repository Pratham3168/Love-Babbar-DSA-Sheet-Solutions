class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
         priority_queue<int> pq;   // Max Heap

        for (int ele : arr) {

            if (pq.size() < k) {
                pq.push(ele);
            }
            else if (ele < pq.top()) {
                pq.pop();
                pq.push(ele);
            }
        }

        return pq.top();
    }
};