#include<bits/stdc++.h>
using namespace std;

class Solution {
  public: 
    
    //find next permutation
    void nestPermutation(vector<int> &arr){
        if(arr.size()==1 || arr.size()==2){
            return reverse(arr.begin(),arr.end());
        }
        
        int pivot = -1;
        int n = arr.size();
        int i = n-2;
        
        
        while(i>=0){
            if(arr[i]<arr[i+1]){
                pivot = i;
                int minIdx = -1;
                for (int j = n - 1; j > pivot; j--) {
                    if (arr[j] > arr[pivot]) {
                        minIdx = j;
                        break;
                    }
                }
                swap(arr[pivot],arr[minIdx]);
                reverse(arr.begin() + i + 1, arr.end());
                break;
            }
            i--;
        }
        
        if(pivot==-1){
            reverse(arr.begin(),arr.end());
        }
    }
    
    void nextPermutation(vector<int>& arr) {
        // code here
        nestPermutation(arr);
    }
};