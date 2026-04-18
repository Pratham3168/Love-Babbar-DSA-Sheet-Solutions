// // User function Template for C++

// class Solution {
//   public:
  
//     int solve(int arr[],int size){
//         stack<int> s;
//         int lowerboundForRight = INT_MIN;
//         for(int i = 0 ;i<size;i++){
//             while(!s.empty() && s.top() < arr[i]){
//                 lowerboundForRight = s.top();
//                 s.pop();
//             }
//             if(lowerboundForRight > arr[i]){
//                 return 0;
//             }
//             s.push(arr[i]);
//         }
//         return 1;
//     }
  
  
//     int canRepresentBST(int arr[], int N) {
//         // code here
//         return solve(arr,N);
//     }
// };