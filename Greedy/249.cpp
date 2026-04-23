#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        //sort both the arrays
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        //pointers to traverse both the arrays in a descending order
        //xp - x pointer
        //yp - y pointer
        int xp = x.size()-1;
        int yp = y.size()-1;
        
        //maintain number of horizontal cuts and vertical cuts
        int horizontal_cut = 1;
        int vertical_cut = 1;
        
        //maintain horizontal cost and vertical cost
        int horizontal_cost = 0;
        int vertical_cost = 0;
        
        
        while(xp >=0 && yp >=0) {
            
            if(x[xp] >= y[yp]){
                vertical_cut++;
                vertical_cost += x[xp] * horizontal_cut;
                xp--;
            }
            else{
                horizontal_cut++;
                horizontal_cost += y[yp] * vertical_cut;
                yp--;
            }
        }
        
        // if any of x remaining
        while(xp >=0) {
            vertical_cut++;
            vertical_cost += x[xp] * horizontal_cut;
            xp--;
        }
        
        //if any of y is remaining
        while(yp >=0) {
            horizontal_cut++;
            horizontal_cost += y[yp] * vertical_cut;
            yp--;
        }
        
        int totalCost = vertical_cost + horizontal_cost;
        
        return totalCost;
        
    }
};
