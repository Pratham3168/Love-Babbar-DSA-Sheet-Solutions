#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int solve(int n, string s) {
        // code here
        unordered_map<char,int> mp;
        unordered_map<char,int> ump;
        
        int cnt=0;
        
        for(int i = 0;i<s.length();i++){
            
            char ele = s[i];
            
            // 1️⃣ If already in ump → ignore
            if (ump.find(ele) != ump.end()) {
                continue;
            }
            
            // 2️⃣ Else if in mp → erase (toggle off)
            if (mp.find(ele) != mp.end()) {
                mp.erase(ele);
            }
            // 3️⃣ Else ele is new (in neither)
            else {
                if (mp.size() < n) {
                    mp[ele] = 1;
                } else {
                    ump[ele] = 1;
                    cnt++;
                }
            }

            
        }
        return cnt;
        
    }
};
