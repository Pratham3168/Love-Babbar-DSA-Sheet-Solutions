#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
      
  
    void twoSum(vector<int> &arr, int target,int start, vector<int> &temp,vector<vector<int>> &ans){
        

        int i = start; 
        int j = arr.size()-1;
        

        while(i<j){
            
            
        
            int sum = arr[i] + arr[j];
            
            if(sum == target){
                temp[2]=arr[i];
                temp[3]=arr[j];
                ans.push_back(temp);
                i++;
                j--;
                
                
                // skip duplicates for i
            while (i < j && arr[i] == arr[i - 1]) i++;

            // skip duplicates for j
            while (i < j && arr[j] == arr[j + 1]) j--;
            }
            else if(sum < target){
                i++;
            }
            else{
                j--;
            }
            
            
        }

    }
  
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> ans;
        vector<int> temp(4,-1);
        
        int sum = 0;
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            
            if (i > 0 && arr[i] == arr[i-1]) continue;

            
            temp[0] = arr[i];
            for(int j =i+1;j<n;j++){
                
                if (j > i+1 && arr[j] == arr[j-1]) continue;

                
                temp[1] = arr[j];
                // FIXED TWO NUMBERS , NOW IMPLEMENT TWO SUM
                twoSum(arr, target - arr[i] -arr[j] , j+1,temp,ans);
                
                
            }
            
        }
        return ans;
        
        
    }
};