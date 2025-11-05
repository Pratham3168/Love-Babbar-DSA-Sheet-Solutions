#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool twoSum(vector<int> arr,int i,int target){
        // while(i<arr.size()){
        //     for(int j=i+1;j<arr.size();j++){
        //         if(arr[i]+arr[j]==target){
        //             return true;
        //         }
        //     }
        //     i++;
        // }
        int j = arr.size()-1;
        while(i<j){
            if(arr[i]+arr[j]==target){
                return true;
            }
            else if(arr[i]+arr[j]>target){
                j--;
            }
            else if(arr[i]+arr[j]<target){
                i++;
            }
        }
        return false;
    }
  
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        sort(arr.begin(),arr.end());
        for(int i =0;i<arr.size();i++){
            int rem = target-arr[i];
            if(twoSum(arr,i+1,rem)){
                return true;
            }
        }
        return false;
    }   
};