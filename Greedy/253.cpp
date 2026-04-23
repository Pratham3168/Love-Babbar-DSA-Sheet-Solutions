#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int maximizeSum(long long int a[], int n, int k) {
        // Your code goes here
        
        //first sort the array
        sort(a,a+n);
        
        long long int sum = 0;
        long long mini = LLONG_MAX;
        for(int i = 0 ;i<n ;i++){
            if(a[i] <0 && k > 0){
                a[i] = -a[i];
                k--;
            }
            sum += a[i];
            mini = min(a[i],mini);
        }
        
        if(k%2 == 1){
            sum -= 2*mini;
        }
        
        return sum;
    }
};