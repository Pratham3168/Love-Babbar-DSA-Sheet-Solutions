#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        
        int n = arr.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int ans =0;
        for(int i =0 ;i<n;i++){
            sum += arr[i];
            if(mp.count(sum)){
                mp[sum]++;
            }
            else{
                mp[sum] =1;
            }
            
        }
        
        for(auto &it:mp){
            
            if(it.second > 1){
                int k = it.second;
                
                ans += (k*(k-1))/2;
            }
            
        }
        
        return ans;
    }
};