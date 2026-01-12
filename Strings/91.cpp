#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        unordered_map<string,vector<string>> mp;
        
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            
            string key = arr[i];
            sort(key.begin(), key.end());
            mp[key].push_back(arr[i]);

            
        }
        
        vector<vector<string>> ans;
        

        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};