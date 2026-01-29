#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
    char getmaxCountChar(vector<int> CntArray){
        int maxi = INT_MIN;
        char ch = '\0';
        
        for(int i = 0 ;i<CntArray.size();i++){
            if(CntArray[i] > maxi){
                ch = 'a' + i;
                maxi = CntArray[i];
            }
        }
        return ch;
        
    }
  
    string RearrangeString(string s){
        int n = s.length();
        vector<int> CntArray(26,0);
        for(int i =0 ; i<n ; i++){
            CntArray[s[i] - 'a'] +=1;
        }
        
        char ch = getmaxCountChar(CntArray);
        int maxCount = CntArray[ch - 'a'];
        
        if(maxCount > (n+1)/2){
            return "";
        }
        
        vector<char> ans(n);
        int idx = 0;
        
        while(maxCount){
            ans[idx] = ch;
            idx +=2;
            maxCount--;
        }
        
        CntArray[ch - 'a'] =0;
        
        for(int i =0;i<CntArray.size();i++){
            while(CntArray[i] > 0){
                if(idx >= n){
                    idx =1;
                }
                ans[idx] = i +'a';
                idx +=2;
                CntArray[i] -=1;
            }
        }
        
        string res ="";
        for(auto ele:ans){
            res += ele;
        }
        return res;
        
    }
  
    string rearrangeString(string s) {
        // code here
        string ans = RearrangeString(s);
        return ans;
        
        
    }
};