// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */

#include<bits/stdc++.h>
using namespace std;
 
 void transpose(vector<vector<int>> &mat){
     int n = mat.size();
     for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
             swap(mat[i][j],mat[j][i]);
         }
     }
 }
 
 void rowRev(vector<int> &row){
     int i = 0;
     int j = row.size()-1;
     
     while(i<=j){
         swap(row[i],row[j]);
         i++;
         j--;
     }
 }
 
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    
    transpose(mat);
    int row = 0;
    while(row<mat.size()){
        rowRev(mat[row]);
        row++;
    }
}
