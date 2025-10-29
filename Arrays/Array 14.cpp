// User function template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n==1){
            return 0;
        }
        sort(arr.begin(),arr.end());
        int diff=arr[n-1]-arr[0];
        int mini,maxi;
        for(int i=0;i<n;i++){
            if(arr[i]-k<0){
                continue;
            }
            maxi=max(arr[i-1]+k,arr[n-1]-k);
            mini=min(arr[0]+k,arr[i]-k);
            diff=min(diff,maxi-mini);
        }
        return diff;
        
    }
};