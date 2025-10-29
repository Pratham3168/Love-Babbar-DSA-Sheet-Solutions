// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
         int mini=INT_MAX;
         int maxi=INT_MIN;
         for(int i=0;i<arr.size();i++){
             if(arr[i]>maxi){
                 maxi=arr[i];
             }
             if(arr[i]<mini){
                 mini=arr[i];
             }
         }
         pair<int,int> ans;
         ans.first=mini;
         ans.second=maxi;
         return ans;
    }
};