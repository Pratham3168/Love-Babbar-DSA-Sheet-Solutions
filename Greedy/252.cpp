#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
     int findMaxProduct(vector<int>& arr) {
        const long long MOD = 1e9 + 7;

        int n = arr.size();
        if(n == 1) return arr[0];

        int neg = 0, zero = 0;
        int skipVal = INT_MIN;

        for(int x : arr){
            if(x < 0){
                neg++;
                skipVal = max(skipVal, x); // closest to zero negative
            }
            else if(x == 0){
                zero++;
            }
        }

        if(zero == n) return 0;

        if(neg == 1 && zero + neg == n) return 0;

        bool removed = false;
        long long ans = 1;
        bool used = false;

        for(int x : arr){
            if(x == 0) continue;

            if((neg & 1) && x == skipVal && !removed){
                removed = true;
                continue;
            }

            ans = (ans * x) % MOD;
            used = true;
        }

        if(!used) return 0;

        if(ans < 0) ans += MOD;

        return (int)ans;
    }
};
