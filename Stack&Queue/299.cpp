class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int size = s.size();
        int k = floor((size + 1)/2);
        stack<int> st;
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            st.push(temp);
        }
        
        int p = 1;
        while(!st.empty()){
            if( p == k){
                st.pop();
                p++;
                continue;
            }
            int temp = st.top();
            st.pop();
            s.push(temp);
            p++;
        }
        
    }
};