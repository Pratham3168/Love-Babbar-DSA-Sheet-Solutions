#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int temp;
        vector<int> ans;
        int i=0;
        int j=0;
        int k=0;
       while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
    if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
        if (ans.empty() || ans.back() != arr1[i])
            ans.push_back(arr1[i]);
        i++; j++; k++;
    }
    else {
        int mn = min({arr1[i], arr2[j], arr3[k]});
        if (arr1[i] == mn) i++;
        if (arr2[j] == mn) j++;
        if (arr3[k] == mn) k++;
    }
}
        return ans;
    }
};