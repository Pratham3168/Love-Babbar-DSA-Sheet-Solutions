#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findMaxValue(vector<vector<int>>& mat, int N) {
        // Write your code here
        vector<vector<int>> maxArr(N, vector<int>(N));
        int maxDiff = INT_MIN;
        
        maxArr[N-1][N-1]=mat[N-1][N-1];
        int maxV = maxArr[N-1][N-1];
        
        //pre-process last row
        for(int j=N-2;j>=0;j--){
            if(mat[N-1][j]>maxV){
                maxV=mat[N-1][j];
            }
            maxArr[N-1][j]=maxV;
        }
        
        //pre-process last Col
        maxV = maxArr[N-1][N-1];
        for(int i=N-2;i>=0;i--){
            if(mat[i][N-1]>maxV){
                maxV=mat[i][N-1];
            }
            maxArr[i][N-1]=maxV;
        }
        
        //pre-process rest of the matrix from bottom
        for(int i=N-2;i>=0;i--){
            for(int j=N-2;j>=0;j--){
                maxDiff = max(maxDiff,maxArr[i+1][j+1]-mat[i][j]);
                maxArr[i][j]=max(mat[i][j],max(maxArr[i+1][j],maxArr[i][j+1]));
            }
        }
        return maxDiff;
    }
};
