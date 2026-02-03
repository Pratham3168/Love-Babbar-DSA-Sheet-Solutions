#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        vector<pair<int,int>> v(arr.size());
        int cnt =0 ;
        
        for(int i =0;i<arr.size();i++){
            
            v[i] = {arr[i],i};
            
        }
        
        sort(v.begin(),v.end());
        
        
        for(int i =0 ;i<arr.size();i++){
            
            
            if(v[i].second == i) continue;
            else{
                cnt++;
                swap(v[i],v[v[i].second]);
                i--;
            }
            
        }
        return cnt;
        
        
    }
};