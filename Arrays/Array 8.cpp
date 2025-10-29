//===========================QUICK SELECT ALGO TO FIND KTH MINIMUM ELEMENT IN AN ARRAY==========================//

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    int quickSelect(vector<int> &arr, int l, int r, int k) {
        int pivot = arr[r];
        int p = l;
        
        for (int i = l; i < r; i++) {
            if (arr[i] <= pivot) {
                swap(arr[p], arr[i]);
                p++;
            }
        }
        swap(arr[p], arr[r]); // Place pivot in the correct position
        
        if (p < k) {
            return quickSelect(arr, p + 1, r, k);
        } else if (p > k) {
            return quickSelect(arr, l, p - 1, k);
        } else {
            return arr[p]; // Found the k-th smallest element
        }
    }

    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // Adjust k to be zero-based index
        k = k - 1; // Convert to 0-based index
        return quickSelect(arr, 0, arr.size() - 1, k);
    }
};

