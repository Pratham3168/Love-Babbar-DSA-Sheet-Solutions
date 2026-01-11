// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    void getSentences(vector<vector<string>> &list,
                        int r,
                        vector<vector<string>>& ans,
                        vector<string> &curr){
        
        
        //base case
        if(r==list.size()){
            ans.push_back(curr);
            return;
        }
        
        
        //including each word from current row
        for(int c = 0;c<list[r].size();c++){
            
            curr.push_back(list[r][c]);
            getSentences(list,r+1,ans,curr);
            curr.pop_back();
            
        }
        
        
        
    }
  
    vector<vector<string>> sentences(vector<vector<string>>& list) {
        // Write your code here
        vector<vector<string>> ans;
        vector<string> curr;
        getSentences(list,0,ans,curr);
        
        return ans;
    }
};
