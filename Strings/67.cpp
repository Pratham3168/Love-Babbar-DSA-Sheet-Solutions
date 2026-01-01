#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubStr(string str) {
        // Write your code here
        int z = 0;
        int o = 0;
        int i = 0;
        int cnt = 0;
        
        while(i<str.length()){
            if(str[i]=='0'){z++;}
            else{o++;}
            
            if(z==o){
                cnt++;
                z=0;
                o=0;
            }
                i++;
            
        }
        if (z != 0 || o != 0) return -1;

        return cnt!=0?cnt:-1;
        
    }
};
