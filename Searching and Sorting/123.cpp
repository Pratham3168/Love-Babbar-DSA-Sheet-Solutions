#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int i =0;
        int j =0;
        int n = a.size();
        int m = b.size();
        
        while(i<n && j<m){
            
            if(a[i] > b[j]){
                k--;
                if(k==0)return b[j];
                j++;
            }
            else{
                k--;
                if(k==0)return a[i];
                i++;
            }
            
        }
        
        while(i<n){
            
            k--;
            if(k==0)return a[i];
            i++;
        }
        while(j<m){
            
            k--;
            if(k==0)return b[j];
            j++;
            
        }
        
        return -1;
        
    }
};