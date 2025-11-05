#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int ans=0;
        int l = 0;
        int r= n-1;
        int leftmax = 0;
        int rightmax = 0;
        
        while(l<r){
            leftmax = max(leftmax,arr[l]);
            rightmax = max(rightmax,arr[r]);
            
            if(leftmax < rightmax){
                ans = ans + ( leftmax - arr[l]);
                l++;
            }
            else{
                ans = ans + (rightmax - arr[r]);
                r--;
            }
        }
        return ans;
    }
};