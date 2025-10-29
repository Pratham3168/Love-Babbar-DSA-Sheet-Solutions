#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int maxSum =INT_MIN ;
        int currSum=0;
        for(int ele:arr){
            currSum+=ele;
            maxSum = max(currSum,maxSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
};