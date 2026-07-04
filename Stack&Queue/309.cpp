class Solution {
  public:
  
    void atBottom(stack<int> &st,int temp){
        if(st.empty()){
            st.push(temp);
            return;
        }
        
        int a = st.top();
        st.pop();
        atBottom(st,temp);
        
        st.push(a);
    }
  
    void solve(stack<int> &st){
        
        //base case
        if(st.empty()){
            return;
        }
        
        int temp = st.top();
        st.pop();
        solve(st);
        
        atBottom(st,temp);
        
    }
  
    void reverseStack(stack<int> &st) {
        // code here
        solve(st);
    }
};