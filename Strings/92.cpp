#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        unordered_map<char,int> need;
        unordered_map<char,int> wind;
        
        int formed = 0;
        int ans = INT_MAX;
        
        int sn = s.length();

        //creating a need map
        for(char c:p){
            need[c]++;
        }
        
        int i = 0;
        int j = 0;
        int start = 0; // start index of the current minimum window

        
        while(i<sn){
            
            char ele = s[i];
            
            wind[ele]++;
            
            if(need.find(ele)!=need.end() && wind[ele] == need[ele]){
                formed++;
            }
            
            
            while(formed == need.size()){ //SHRINKING WINDOW
            
                if (i - j + 1 < ans) {
                    ans = i - j + 1;  // new minimum length
                    start = j;        // record where it starts
                }
                char temp = s[j];
                wind[temp]--;
                
                if(need.find(temp) != need.end() && wind[temp] < need[temp]){
                    formed--;
                }
                j++;
            }
            
            i++;
            
        }
        
        if (ans == INT_MAX) return "";  // no valid window
        return s.substr(start, ans);    // smallest window substring
        
    }
};