#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int range=arr[0];
        int temp;
        int i=0;
        int ans=0;
        int n=arr.size();
        while(range<n-1){
            temp=range;
            while(i<n && i<=range){
                temp=max(temp,arr[i]+i);
                i++;
            }
            if(range==temp && i<n){
                return -1;
            }
            range=temp;
            ans++; 
        }
        return ans+1;
    }
};