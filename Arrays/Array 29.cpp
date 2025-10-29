#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int count = 1 ;
        int temp = 1;
        sort(arr.begin(),arr.end());
        for(int i = 0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==1){
                temp++;
            }
            else if(arr[i+1]==arr[i]){
                continue;
            }
            else{
                temp = 1;
            }
            count = max(temp,count);
        }
        return count;
        
    }
};