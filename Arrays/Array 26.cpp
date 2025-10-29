#include<unordered_map>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        unordered_map<int,int> mp;
        int sum = 0;
        for(int i = 0; i<arr.size();i++){
            sum +=arr[i];
            if(sum == 0 || mp.find(sum) != mp.end()){
                return true;
            }
            else{
                mp.insert({sum,0});
            }
        }
        return false;
    }
};