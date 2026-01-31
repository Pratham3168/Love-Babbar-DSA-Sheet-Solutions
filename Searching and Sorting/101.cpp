#include<bits/stdc++.h>
using namespace std;

class Solution {
  
  public:
  
    //first occurence
    int firstOcc(vector<int> &arr,int x,int n){
        
        int s = 0;
        int e = n-1;
        
        int ans = -1;
        int mid = s + (e-s)/2;
        
        while(s<=e){
            
            if(arr[mid] == x){
                ans = mid;
                e = mid -1;
            }
            else if(arr[mid] > x){
                e = mid-1;
            }
            else {
                s = mid +1;
            }
            mid = s + (e-s)/2;
            
        }
        return ans;
        
    }
    
    //last occurence
    int lastOcc(vector<int> &arr,int x,int n){
        
        int s = 0;
        int e = n-1;
        
        int ans = -1;
        int mid = s + (e-s)/2;
        
        while(s<=e){
            
            if(arr[mid] == x){
                ans = mid;
                s = mid + 1;
            }
            else if(arr[mid] > x){
                e = mid-1;
            }
            else {
                s = mid +1;
            }
            mid = s + (e-s)/2;
            
        }
        return ans;
        
    }
  
    vector<int> find(vector<int>& arr, int x) {
        // code here
        
        int n = arr.size();
        
        vector<int> ans;
        
        int first = firstOcc(arr,x,n);
        int last = lastOcc(arr,x,n);
        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
        
        
    }
};