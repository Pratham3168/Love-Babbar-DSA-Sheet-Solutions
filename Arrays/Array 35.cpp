#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int ans= INT_MAX;
        int diff=0;
        sort(a.begin(),a.end());
        int i=0;
        int j=i+m-1;
        
        while(j<a.size()){
            diff = a[j]-a[i];
            ans = min(diff,ans);
            
            i++;
            j++;
            
        }
        
        return ans;
    }
};