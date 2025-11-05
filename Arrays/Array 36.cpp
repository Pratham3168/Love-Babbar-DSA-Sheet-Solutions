#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int cnt = INT_MAX ;
        int temp = 0;
        int i = 0 ;
        int sum = 0;
        for(int j =0 ; j<arr.size();j++ ){
            sum +=arr[j];
            
            while(sum  > x){
                cnt = min(cnt,j-i+1);
                sum -= arr[i];
                i++;
            }
            
            
        }
        if(cnt!=INT_MAX){
            return cnt;
        }
        return 0;
    }
};