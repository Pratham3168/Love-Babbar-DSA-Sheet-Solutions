// User function template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        vector<int> temp(2);
        temp[0] = INT_MAX;
        temp[1] = INT_MIN;
        vector<vector<int>> ans;
        int i=0;
        int j=arr.size()-1;
        sort(arr.begin(),arr.end());
        while(i<j){
            if(abs(arr[i])>abs(arr[j])){
                i++;
            }
            else if(abs(arr[i])<abs(arr[j])){
                j--;
            }
            else{
                if(arr[i] + arr[j] == 0){
                    if(temp[0]!=arr[i]  &&  temp[1]!=arr[j]){
                        temp[0]=arr[i];
                        temp[1]=arr[j];
                        ans.push_back(temp);
                    }
                    i++;
                    j--;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};