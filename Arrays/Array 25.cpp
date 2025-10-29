// User function template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos;
        vector<int> neg;
        for(int ele : arr){
            if(ele>=0){
                pos.push_back(ele);
            }
            else{
                neg.push_back(ele);
            }
        }
        
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<pos.size() && j<neg.size()){
            if(k==0){
                arr[k] = pos[i];
                i++;
                k++;
            }
            if(arr[k-1]>=0){
                arr[k] = neg[j];
                j++;
                k++;
            }
            else{
                arr[k] = pos[i];
                i++;
                k++;
            }
        }
        
        while(i<pos.size()){
            arr[k] = pos[i];
            k++;
            i++;
        }
        
        while(j<neg.size()){
            arr[k]=neg[j];
            k++;
            j++;
        }
        
    }
};