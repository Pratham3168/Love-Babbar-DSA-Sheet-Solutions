class Solution {
  public:

    int solve(int remaining, int x, int y, int z, vector<int>& dp) {

        // base case
        if(remaining == 0) {
            return 0;
        }

        if(remaining < 0) {
            return INT_MIN;
        }

        if(dp[remaining] != -1) {
            return dp[remaining];
        }

        // using x
        int cutX = solve(remaining - x, x, y, z, dp);

        // using y
        int cutY = solve(remaining - y, x, y, z, dp);

        // using z
        int cutZ = solve(remaining - z, x, y, z, dp);

        return dp[remaining] =
            1 + max(cutX, max(cutY, cutZ));
    }

    int maximizeCuts(int n, int x, int y, int z) {

        vector<int> dp(n + 1, -1);

        int ans = solve(n, x, y, z, dp);

        return max(0, ans);
    }
};