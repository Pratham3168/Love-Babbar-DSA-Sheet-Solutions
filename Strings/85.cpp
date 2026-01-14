#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int minimumNumberOfSwaps(string& s) {
        // code here
        int open = 0, close = 0, unbalanced = 0, swaps =0;
        
        for(int i=0;i<s.length();i++){
            
            char ele = s[i];
            
            if(ele == '['){
                open++;
                if(unbalanced > 0){
                    swaps+=unbalanced;
                    unbalanced--;
                }
            }
            else{
                close++;
                unbalanced = close - open;
            }
            
            
        }
        
        return swaps;
        
    }
};