class Solution {
  public:
  
    //optimal approach
    // int majorityElement(vector<int>& arr) {
    //     int n = arr.size();
    //     if (n == 0) return -1;
    //     if (n == 1) return arr[0];  // ⭐ important fix

    //     sort(arr.begin(), arr.end());

    //     int freq = 1;

    //     for(int i = 1; i < n; i++){
    //         if(arr[i] == arr[i-1]){
    //             freq++;
    //             if(freq > n/2)
    //                 return arr[i];
    //         } else {
    //             freq = 1;
    //         }
    //     }
    //     return -1; // no majority element
    // }
    
    
    
    
    // MOORE'S VOTING ALGORITHM
    // int majorityElement(vector<int>& arr) {
    //     int n = arr.size();
    //     int freq = 0;
    //     int ans = 0;
    //     for(int i =0;i<n;i++){
            
    //         if(freq == 0){
    //             ans = arr[i];
    //         }
    //         if(ans == arr[i]){
    //             freq++;
    //         }
    //         else{
    //             freq--;
    //         }
            
    //     }
    //     freq = 0;
    //     for (int x : arr){
    //         if (x == ans) freq++;
    //     }
    //     return (freq > n / 2) ? ans : -1;
    // }
};