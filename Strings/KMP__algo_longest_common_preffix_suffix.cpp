#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        vector<int> lps(s.length(),0);
        int pre=0,suf =1;
        
        while(suf<s.length()){
            //IF MATCHED
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                suf++;
                pre++;
            }
            //IF NOT MATCHED --> PREFIX GOES BACK TO MATCH SUFFIX
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
        return lps[s.length()-1];
    }
};