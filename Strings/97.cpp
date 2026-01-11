#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        
        
        unordered_map<char,char> m1;
        unordered_map<char,char> m2;
        
        
        int n=s1.length();
        
        
        for(int i=0;i<n;i++){
            
            char c1 = s1[i];
            char c2 = s2[i];
            
            
            if(m1.count(c1)){
                if(m1[c1] != c2){
                    return false;
                }
            }
            else{
                m1[c1] = c2;
            }
            
            if(m2.count(c2)){
                if(m2[c2] != c1){
                    return false;
                }
            }
            else{
                m2[c2] = c1;
            }
            
        }
        return true;
    }
};