class Solution {
  public:
  
    vector<vector<string>> ans;
    vector<string> temp;

  
  
    bool palindrome(string &st){
        if(st.length() == 0){
            return false;
        }
        
        if(st.length() == 1){
            return true;
        }
        
        int i = 0;
        int j = st.length()-1;
        
        while(i <= j){
            if(st[i] != st[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
  
  
    void solve(int i,string &s){
        
        // base case
        if(i >= s.length()){
            ans.push_back(temp);
            return ;
        };
        string sub = "";

        
        for(int k = i ; k < s.length(); k++){
            
            //generate substring
            sub = sub + s[k];
            
            if(palindrome(sub)){
                temp.push_back(sub);
                solve(k+1, s);
                temp.pop_back();
            }
            
        }
    }
  
  
    vector<vector<string>> palinParts(string &s) {
        // code here
        solve(0,s);
        return ans;
    }
};