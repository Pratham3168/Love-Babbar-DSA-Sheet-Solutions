//==============BRUTE FORCE APPROACH=================
// class Solution {
//   public:
//     int rowWithMax1s(vector<vector<int>> &arr) {
//         // code here
//         int ans=-1;
//         int cnt=INT_MIN;
//         int row=arr.size();
//         int col=arr[0].size();
        
//         for(int i=0;i<row;i++){
//             for(int j=0;j<col;j++){
//                 if(arr[i][j]==1){
//                     int temp = col-j;
//                     if(temp>cnt){
//                         cnt=temp;
//                         ans=i;
//                     }
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };

//==============OPTIMAL APPROACH=================
// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
//   public:
//     int rowWithMax1s(vector<vector<int>> &arr) {
//         // code here
//         int n = arr.size();
//         int m = arr[0].size();
//         int row = 0;
//         int col = m-1;
//         int cnt = 0;
//         int maxCnt = 0;
//         int ans=-1;
//         while(row<n){
//             if(arr[row][col]==1 && col>=0){
//                 col--;
//                 cnt++;
//                 if(cnt>maxCnt){
//                     ans = row;
//                 }
//             }
//             else{
//                 row++;
//             }
//         }
//         return ans==-1?-1:ans;
//     }
// };