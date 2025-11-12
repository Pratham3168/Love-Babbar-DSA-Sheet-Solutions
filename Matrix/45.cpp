#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool BinarySearch(vector<int> mat,int target){
        int i = 0;
        int j = mat.size()-1;
        int mid = i+ (j-i)/2;
        while(i<=j){
            mid = i + (j-i)/2;
            if(mat[mid]==target){
                return true;
            }
            else if(mat[mid]>target){
                j=mid-1;
            }
            else if(mat[mid]<target){
                i=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int top = 0;
        int n = matrix[0].size();
        int bottom = m-1;
        int mid = top + (bottom - top)/2;
        while(top<=bottom){
            mid = top + (bottom - top)/2;

            if(matrix[mid][n-1] < target){
                top = mid + 1;
            }
            else if (matrix[mid][0] > target){
                bottom = mid-1;
            }
            else {
                return BinarySearch(matrix[mid],target);
            }
        }
        return false;
    }
};