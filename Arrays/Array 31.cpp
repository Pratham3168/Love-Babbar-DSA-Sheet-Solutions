#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int *profit = new int[n];
        
        for(int i=0;i<n;i++){
            profit[i]=0;
        }
        
        int max_pp = prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prices[i]>max_pp){
                max_pp=prices[i];
            }
            profit[i] = max(profit[i+1],max_pp-prices[i]);
        }
        
        int min_pp = prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<min_pp){
                min_pp=prices[i];
            }
            profit[i] = max(profit[i-1],profit[i]+prices[i]-min_pp);
        }
        int result  = profit[n-1];
        delete[] profit;
        return result;
    }
};