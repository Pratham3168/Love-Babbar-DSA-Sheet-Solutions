class Solution {
public:

    int solve(int i, int n, vector<int>& arr, int consCount,
              vector<vector<int>>& dp) {

        if (i >= n)
            return 0;

        if (dp[i][consCount] != -1)
            return dp[i][consCount];

        // Include
        int included = 0;

        if (consCount < 2) {
            included = arr[i] +
                       solve(i + 1, n, arr, consCount + 1, dp);
        }

        // Exclude -> consecutive count becomes 0
        int excluded = solve(i + 1, n, arr, 0, dp);

        return dp[i][consCount] = max(included, excluded);
    }

    int findMaxSum(vector<int>& arr) {

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(3, -1));

        return solve(0, n, arr, 0, dp);
    }
};