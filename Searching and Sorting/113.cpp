#include <bits/stdc++.h>    
using namespace std;

class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here\
        
        long long ans=0;
        sort(arr, arr + n);
        
        for(int i=0;i<n;i++){
            if(arr[i] >= sum)continue;
            
            // NOW USE TWO POINTERS
            
            int j = i+1;
            int k = n-1;
            
            while(j<k){
                
                if(arr[i] + arr[j] + arr[k] < sum){
                    ans += k-j;
                    j++;
                }
                else if(arr[i] + arr[j] +arr[k] >=sum){
                    k--;
                }
                
                
            }
            
        }
        return ans;
        
    }
};