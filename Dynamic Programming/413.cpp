class Solution {
  public:
  
  long long solve(int n, int r) {

      if(r == 0)
          return 1;

      return n * solve(n - 1, r - 1);
  }
  
    long long nPr(int n, int r) {
        // code here
        return solve(n,r);
    }
};