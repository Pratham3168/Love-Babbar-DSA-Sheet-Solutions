#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        
        //sort the array
        sort(a.begin(),a.end());
        int n = a.size();
        
        int minDiff = INT_MAX;
        
        int i = 0;

        for (int i = 0; i + m - 1 < n; i++) {
            int diff = a[i + m - 1] - a[i];
            minDiff = min(minDiff, diff);
        }
        
        return minDiff;
        
        
    }
};