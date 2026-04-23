#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxValue(vector<int> &arr) {
        // Complete the function
        sort(arr.begin(),arr.end());
        long long mod = 1e9 + 7;
        long long sum = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            long long term = ((arr[i] % mod) * (i % mod)) % mod;
            sum = (sum + term) % mod;
        }
        
        return sum;
    }
};