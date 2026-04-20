#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.first<b.first;
    }
  
  
    int buyMaximumProducts(int k, vector<int> price) {
        // code here
        vector<pair<int,int>> v;
        for(int i = 0; i< price.size();i++){
            v.push_back(make_pair(price[i], i+1));
        }
        
        sort(v.begin(),v.end(),cmp);
        int stocks = 0;
        int budget = k;
        
        for(int i = 0; i<v.size() ; i++){
            pair<int,int> ele = v[i];
            int limit = ele.second;
            int dayPrice = ele.first;
            int dayCount = min(limit,budget/dayPrice);
            budget -= dayPrice*dayCount;
            stocks+=dayCount;
        }
        return stocks;
    }
};
