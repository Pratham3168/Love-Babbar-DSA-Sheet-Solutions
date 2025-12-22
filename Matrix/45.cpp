#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int i=rows-1;
        int j=0;

        while(i>=0 && j<cols){
            int ele = matrix[i][j];
            if(ele==target){
                return 1;
            }
            else if(ele<target){
                j++;
            }
            else if(ele>target){
                i--;
            }
        }
        return 0;
    }
};