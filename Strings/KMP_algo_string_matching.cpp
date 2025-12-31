#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> lpsform(string& s){
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
        return lps;
    }
    

    int strStr(string haystack, string needle) {
        // int n = haystack.length(),m=needle.length();
        // int first =0;
        // int second=0;
        // for(int i=0;i<=n-m;i++){
        //     first=i;second = 0;
        //     while(second<m){
        //         if(haystack[first]!=needle[second]){
        //             break;
        //         }
        //         else{
        //             first++;
        //             second++;
        //         }
                
        //     }
        //     if(second==m){
        //         return first-second;
        //     }
        // }
        // return -1;



        //OPTIMAL APPROACH
        // vector<int> lps = lpsform(needle);
        // int n = haystack.length(),m=needle.length();
        // int first=0,second=0;

        // while(second<m && first<n){
        //     if(haystack[first]!=needle[second]){
        //         second!=0?(second=lps[second-1]):(first++);
        //     }
        //     else{
        //         first++;
        //         second++;
        //         if(second==m){
        //             return first-second;
        //         }
        //     }
        // }
        

        // return -1;
    }
};