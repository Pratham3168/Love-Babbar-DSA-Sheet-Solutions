#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minFlips(string& s) {
        // code here
        int c1 = 0;
        int c2 = 0;
        
        for(int i = 0;i<s.length();i++){
            
            if(i&1 and s[i] == '0') c1++;
            if(i%2 == 0 and s[i] == '1') c1++;
            if(i&1 and s[i] == '1') c2++;
            if(i%2 == 0 and s[i] == '0') c2++;
            
        }
        
        return min(c1,c2);
    }
};
