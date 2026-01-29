// USING ONLY RECURSION
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    bool f(int i,int j,string &pattern,string &wild){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0){
            for(int ii=0;ii<i;ii++){
                if(wild[ii] != '*') return false;
            }
            return true;
        }
        
        if(wild[i] == pattern[j] || wild[i] == '?'){
            return f(i-1,j-1,pattern,wild);
        }
        if(wild[i] == '*'){
            return f(i-1,j,pattern,wild) | f(i,j-1,pattern,wild);
        }
        return false;
        
    }
  
    bool match(string wild, string pattern) {
        // code here
        int n = wild.size();
        int m = pattern.size();
        
        return f(n-1,m-1,pattern,wild);
    }
};