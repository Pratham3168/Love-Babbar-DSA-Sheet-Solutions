class Solution {
public:

    int solve(int floors, int eggs, vector<vector<int>>& dp) {

        if (floors == 0 || floors == 1)
            return floors;

        if (eggs == 1)
            return floors;

        if (dp[floors][eggs] != -1)
            return dp[floors][eggs];

        int ans = INT_MAX;

        int low = 1;
        int high = floors;

        while (low <= high) {

            int x = low + (high - low) / 2;

            int breakCase =
                solve(x - 1, eggs - 1, dp);

            int notBreakCase =
                solve(floors - x, eggs, dp);

            int worstCase =
                1 + max(breakCase, notBreakCase);

            ans = min(ans, worstCase);

            if (breakCase < notBreakCase) {
                // Need to move right
                low = x + 1;
            }
            else {
                // Need to move left
                high = x - 1;
            }
        }

        return dp[floors][eggs] = ans;
    }

    int eggDrop(int n, int k) {

        vector<vector<int>> dp(
            k + 1,
            vector<int>(n + 1, -1)
        );

        return solve(k, n, dp);
    }
};