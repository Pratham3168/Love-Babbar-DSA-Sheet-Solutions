#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int N = mat.size();
        int M = mat[0].size();
        vector<int> hst(M,0);
        int maxarea = INT_MIN;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(mat[i][j]==1){
                    hst[j]+=1;
                }
                else{
                    hst[j]=0;
                }
            }
            vector<int> nse(M);//next smaller
            vector<int> pse(M);//previous smaller
            
            stack<int> s;
            s.push(-1);
            //finding next smaller
            for(int i=M-1;i>=0;i--){
                int curr = hst[i];
                while(s.top() != -1 && hst[s.top()]>=curr){
                    s.pop();
                }
                nse[i] = s.top();
                s.push(i);
            }
            
            // Empty the stack using a while loop
            while (!s.empty()) {
                s.pop();
            }
            s.push(-1);
            
            //previous smaller element
            for(int i=0;i<M;i++){
                int curr = hst[i];
                while(s.top() != -1 && hst[s.top()]>=curr){
                    s.pop();
                }
                pse[i]=s.top();
                s.push(i);
            }
            
            
            //compute max area
            for(int i=0;i<M;i++){
                if(nse[i]==-1){
                    nse[i]=M;
                }
                int w = nse[i]-pse[i]-1;
                int area = hst[i]*w;
                maxarea = max(maxarea,area);
            }
        }
        
       
        return maxarea;
        
    }
};