#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  
    int getMinCost(vector<int> &prices,int k){
        
        int i = 0;
        int j = prices.size()-1;
        int price = 0;
        
        while(i <= j){
            price += prices[i];
            j -= k;
            i++;
        }
        return price;
    }
    
    int getMaxCost(vector<int> &prices,int k){
        int i = 0;
        int j = prices.size()-1;
        int price = 0;
        
        while(i <= j){
            price += prices[j];
            i += k;
            j--;
        }
        return price;
    }
  
  
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        //1 2 3 4 5
        //sorting the prices array, to use two pointers
        sort(prices.begin(),prices.end());
        
        int MinCost = getMinCost(prices,k);
        int MaxCost = getMaxCost(prices,k);
        
        vector<int> ans(2);
        ans[0] = MinCost;
        ans[1] = MaxCost;
        
        return ans;
        
    }
};