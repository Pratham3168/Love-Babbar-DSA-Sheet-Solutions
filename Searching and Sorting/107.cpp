#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int dup = 0;
        int n = arr.size();
        int miss = 0;
        vector<int> ans;
        sort(arr.begin(),arr.end());
        if(arr[0] != 1) miss = 1;
        
        for(int i =0;i<arr.size()-1;i++){
            
            if(arr[i] == arr[i+1]){
                dup = arr[i];
            }
            else if(arr[i] + 1 != arr[i+1]){
                miss = arr[i] + 1;
            }
            
        }
        
        if(arr[n-1] != n) miss = n;
        return {dup, miss};
    }
    
};