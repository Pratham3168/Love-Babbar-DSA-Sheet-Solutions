#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    string helper(string &s,int l, int r,int n){
        while(l>=0 && r<n && s[l]==s[r] ){
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
  
    string longestPalindrome(string &s) {
        // code here    
        
        int n = s.length();
        string ans = "";
        
        for(int i=0;i<n;i++){
            string s1 = helper(s,i,i,n); //ASSUMING ODD LENGTH
            string s2 = helper(s,i,i+1,n); //ASSUMING EVEN LENGTH
            
            
            if(ans.length()<s1.length()){
                ans=s1;
            }
        
            if(ans.length()<s2.length()){
                ans=s2;
            }
      
        }
        
        return ans;
        
    }
};