// Final function implementation
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int cnt =0;
        int currCnt =0;
        // int ans=INT_MAX;
        int n= arr.size();
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=k) {cnt++;}
        }
        for(int i =0;i<cnt;i++){
            if(arr[i]<=k) {currCnt++;}
        }
        int ans = cnt-currCnt;
        for(int i=cnt;i<n;i++){
            if(arr[i]<=k){
                currCnt++;
            }
            if(arr[i-cnt]<=k){
                currCnt--;
            }
            ans=min(ans,cnt-currCnt);
        }
        return ans;
    }
};