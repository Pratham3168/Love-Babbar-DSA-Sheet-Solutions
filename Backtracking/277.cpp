// User function Template for C++
class Solution {
  public:
  
    bool isMatch(string &w, int i, string &s){
        if (i + w.size() > s.size()) return false;

        for (int k = 0; k < w.size(); k++) {
            if (s[i + k] != w[k]) return false;
        }
    
        return true;
    }
  
    void solve(vector<string> &dict, string &s, vector<string> &ans,int i,string temp){
        
        //base case
        if(i >= s.length()){
            ans.push_back(temp);
            return;
        }
        
        for(auto ele : dict){
            if(isMatch(ele, i, s)){
                if(temp.length() ==0 ){
                    solve(dict,s,ans,i + ele.length(),temp + ele);
                }
                else{
                    solve(dict,s,ans,i + ele.length(),temp + " " + ele);
                }
                
            }
        }
        
        
    }
  
  
    vector<string> wordBreak(vector<string>& dict, string& s) {
        // code here
        
        vector<string> ans;

        solve(dict,s,ans,0,"");
        
        return ans;
        
    }
};