class Solution {
  public:
  
    int solve(int n){
        
        if( n == 0 || n == 1){
            return 1;
        }
        
        //stays single
        int single = solve(n-1);
        
        //gets paired
        int paired = (n-1)*solve(n-2);
        
        return single + paired;
    }
  
    int countFriendsPairings(int n) {
        // code here
        return solve(n);
    }
};
