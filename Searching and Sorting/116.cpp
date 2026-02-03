#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        
        //BRUTE FORCE
        // int zCnt =0 ;
        // vector<int> ans(arr.size(),0);
        // for(int ele :arr){
        //     if(ele == 0){
        //         zCnt++;
        //     }
        // }
        
        // if(zCnt > 1)return ans;
        
        // int pro = 1;
        // for(int ele : arr){
        //     if(ele != 0){
        //         pro = pro * ele;
        //     }
        // }
        
        // for(int i =0 ;i<arr.size();i++){
            
        //     if(arr[i] == 0){
        //         ans[i] = pro;
        //     }
        //     else if(zCnt ==1){
        //         ans[i] = 0;
        //     }
        //     else{
        //         ans[i] = pro/arr[i];
        //     }
            
        // }
        // return ans;
        
        
        //PREFIX-SUFFIX
        int prefix =1;
        int suffix =1;
        
        int i =0 ;
        int n =arr.size();
        vector<int> ans(arr.size(),0);
        
        
        //making prefix
        while(i<n){
            
            ans[i] = prefix;
            prefix = prefix * arr[i];
            i++;
            
        }
        
        int j = n-1;
        while(j>=0){
            
            ans[j] = ans[j] * suffix;
            suffix = suffix*arr[j];
            j--;
            
        }
        
        return ans;
    }
};
