#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        // code here.
        
        string ans="";
        int n=s.length();
        char temp = s[0];
        ans+=s[0];
        
        for(int i=1;i<n;i++){
            
            if(s[i]!=temp){
                ans+=s[i];
                temp = s[i];

            }
            
            
        }
        
        return ans;
        
    }
};