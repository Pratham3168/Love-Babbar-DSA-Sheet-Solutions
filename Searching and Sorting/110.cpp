#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    // bool binarySearch(vector<int> &arr,int i,int k){
        
    //     int n = arr.size();
    //     int j = n-1;
    //     int mid = i + (j-i)/2;
        
    //     while(i<=j){
    //         if(arr[mid] == k){
    //             return true;
    //         }
    //         else if(arr[mid] > k){
    //             j = mid -1;                
    //         }
    //         else if(arr[mid] < k ){
    //             i = mid +1;
    //         }
    //         mid = i + (j-i)/2;
    //     }
    //     return false;
        
    // }
  
    // bool findPair(vector<int> &arr, int x) {
    //     // code here
    //     int n = arr.size();
         
    //     if(n==1 || n==0) return false;
        
    //     sort(arr.begin(),arr.end());
        
    //     for(int i =0;i<n;i++){
            
    //         if (binarySearch(arr, i + 1, arr[i] + x))
    //         return true;
            
    //     }
        
    //     return false;
    // }
    
    
    
    bool findPair(vector<int> &arr, int x) {
        // code here
        int n = arr.size();
         
        if(n==1 || n==0) return false;
        
        sort(arr.begin(),arr.end());
        
        int i = 0,j=1;
        
        while(j<n){
            
            int diff = arr[j] - arr[i];
            
            if(diff == x && i!=j )return true;
            else if(diff < x){
                j++;
            }
            else{
                i++;
            }
            
            if(i==j)j++;
        }
        
        return false;
    }
};