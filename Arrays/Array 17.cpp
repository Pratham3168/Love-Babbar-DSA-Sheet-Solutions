// class Solution {
//   public:
  
  
//     void mergeArrays(vector<int>& a, vector<int>& b) {
//         // code here
//         int m = a.size();
//         int n = b.size();
//         for(int i=0;i<n;i++){
//             a.push_back(b[i]);
//         }
//         int k = a.size();
//         sort(a.begin(), a.end());
//         for(int i = m ;i<k;i++){
//             b[i-m]=a[i];
//         }
        
//         for(int j = 0;j<n;j++){
//             a.pop_back();
//         }
        
//     }
// };

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();

        // Start from the end
        int i = m - 1;
        int j = 0;

        // Step 1: Swap out-of-order elements
        while (i >= 0 && j < n) {
            if (a[i] > b[j]) {
                swap(a[i], b[j]);
            }
            i--;
            j++;
        }

        // Step 2: Re-sort both arrays individually
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};