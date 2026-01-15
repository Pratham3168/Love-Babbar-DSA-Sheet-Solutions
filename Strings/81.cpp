#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        int n = s.length();
        int deci = 0;
        unordered_map<char, int> mp = {
                                        {'I', 1},
                                        {'V', 5},
                                        {'X', 10},
                                        {'L', 50},
                                        {'C', 100},
                                        {'D', 500},
                                        {'M', 1000}
                                    };

        
        for(int i=0;i<s.length();i++){
            
            if(i == n-1){
                deci += mp[s[i]];
            }
            
            //if next value is small
            else if(mp[s[i+1]] <= mp[s[i]]){
                
                deci += mp[s[i]];
                
            }
            
            
            //if next value is greater
            else if(mp[s[i+1]] > mp[s[i]]){
                
                deci += mp[s[i+1]] - mp[s[i]];
                i += 1;
                
            }
            
            
            
        }
        
        return deci;
    }
};