#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    int merge(vector<int> &arr,int st, int mid, int end){
        int i = st;
        int j = mid+1;
        vector<int> temp;
        int invCounts = 0;
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
                invCounts += mid - i + 1;
            }
        }
        
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=mid){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int idx = 0;idx<temp.size();idx++){
            arr[idx+st] = temp[idx];
        }
        return invCounts;
    }
  
    int mergeSort(vector<int> &arr,int st,int end){
        if(st<end){
            int mid = st + (end-st)/2;
            
            int leftInvCount = mergeSort(arr,st,mid);
            int rightInvCount = mergeSort(arr,mid+1,end);
            
            int invCount = merge(arr,st,mid,end);
            
            return leftInvCount + rightInvCount + invCount;
        }
        return 0;
    }   
  
    int inversionCount(vector<int> &arr) {
        // Code Here
        int st = 0;
        int end = arr.size()-1;
        int ans = mergeSort(arr,st,end);
        return ans;
        
        
    }
};