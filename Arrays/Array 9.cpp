
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int l=0;
        int m=0;
        int h=arr.size()-1;
        while(m<=h){
            if(arr[m]==0){
                swap(arr[l],arr[m]);
                m++;
                l++;
            }
            else if(arr[m]==1){
                m++;
            }
            else if(arr[m]==2){
                swap(arr[m],arr[h]);
                h--;
            }
        }
    }
};