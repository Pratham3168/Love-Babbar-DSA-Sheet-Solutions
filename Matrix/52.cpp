#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int s = mat[0][0];
        int n =mat.size();
        int e = mat[n-1][n-1];
        int mid = s + (e-s)/2;
        int cnt=0;
        int ans=0;
        while(s<=e){
            mid = s + (e-s)/2;
            cnt=0;
            int i = n - 1;
            int j = 0;
            
            while (i >= 0 && j < n) {
                if (mat[i][j] <= mid) {
                    cnt += (i + 1);   // all elements above are ≤ mid
                    j++;              // move right
                } 
                else {
                    i--;              // move up
                }
            }
            if(cnt>=k){
                ans=mid;
                e=mid-1;
                mid= s + (e-s)/2;
            }
            else if(cnt<k){
                s=mid+1;
                mid  = s + (e-s)/2;
            }
        }
        return ans;
    }
};
