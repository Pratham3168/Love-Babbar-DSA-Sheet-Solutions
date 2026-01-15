#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        set<char> s;
        for(char ele:str){
            s.insert(ele);
        }
        unordered_map<char,int> m;
        
        int ans=str.length();
        int i=0;
        int j=0;
        int n = s.size();
        
        while(i<str.length()){
            
            m[str[i]]++;
            
            if(m.size() == n){
                
                while(m[str[j]]>1){
                    m[str[j]]--;
                    j++;
                }
                ans = min(ans,i-j+1);
            }
            i++;
            
        }
        
        return ans;
    }
    
};