#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int matsize = n*m;
        int l=0;
        int t=0;
        int r=m-1;
        int b=n-1;
        int k=1;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<int> res(matsize);
        res[0] = mat[0][0];
        visited[0][0]=1;
        while(k<matsize){
            while(l < r && visited[t][l+1] == 0){  // move right
                l++;
                res[k++] = mat[t][l];
                visited[t][l] = 1;
            }
            while(t < b && visited[t+1][l] == 0){  // move down
                t++;
                res[k++] = mat[t][l];
                visited[t][l] = 1;
            }
            while(l > 0 && visited[t][l-1] == 0){  // move left
                l--;
                res[k++] = mat[t][l];
                visited[t][l] = 1;
            }
            while(t > 0 && visited[t-1][l] == 0){  // move up
                t--;
                res[k++] = mat[t][l];
                visited[t][l] = 1;
            }
        }
        return res;
    }
};