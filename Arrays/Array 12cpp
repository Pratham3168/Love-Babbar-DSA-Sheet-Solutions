// User function Template for C++
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        vector<int> temp(arr.size());
        int k = arr.size();
        for(int i=0;i<arr.size();i++){
            temp[(i+1)%k] = arr[i];
        }
        for(int i=0;i<k;i++){
            arr[i]=temp[i];
        }
    }
};