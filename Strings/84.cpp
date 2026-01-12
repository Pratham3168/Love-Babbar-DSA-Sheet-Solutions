#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string secFrequent(string arr[], int n) {
        // code here.
        unordered_map<string,int> freq;
        
        for(int i=0;i<n;i++){
            
            if(freq.count(arr[i])){
                freq[arr[i]] += 1;
            }
            else {
                freq[arr[i]] = 1;
            }
            
        }
        
        int max1 = 0, max2 = 0;
        for(auto &it : freq){
            if(it.second > max1){
                max2 = max1;
                max1 = it.second;
            }
            else if(it.second < max1 && it.second > max2){
                max2 = it.second;
            }
        }
        
        string ans= "";
        int mapSize = freq.size();
        for(auto &it:freq){
            
            if(it.second == max2)
            return it.first;
            
            
        }
        
        return ans;
        
    }
};