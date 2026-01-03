#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
        for(int i = 0;i<s.length();i++){
            if(st.empty()){
                
                st.push(s[i]);
                continue;
            }
            
            
            if(s[i]==')'){
                if(st.top() == '('){
                    st.pop();
                    continue;
                }
               
            }
            else if(s[i]=='}'){
                if(st.top() == '{'){
                    st.pop();
                    continue;
                }
                
            }
            else if(s[i]==']'){
                if(st.top() == '['){
                    st.pop();
                    continue;
                }
                
            }
            
            st.push(s[i]);
            
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};