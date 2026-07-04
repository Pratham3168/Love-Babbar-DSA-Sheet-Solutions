class Solution {
public:
    int totalSum;

    bool solve(int i, vector<int> &arr, int sum, vector<vector<int>> &dp) {

        // base case
        if (sum == totalSum / 2) return true;

        if (sum > totalSum / 2) return false;

        if (i >= arr.size()) return false;

        if (dp[i][sum] != -1) return dp[i][sum];

        // include
        bool included = solve(i + 1, arr, sum + arr[i], dp);

        // exclude
        bool excluded = solve(i + 1, arr, sum, dp);

        return dp[i][sum] = (included || excluded);
    }

    bool equalPartition(vector<int>& arr) {

        int sum = 0;
        for (int ele : arr) sum += ele;

        if (sum % 2 != 0) return false;

        totalSum = sum;
        int target = totalSum / 2;
        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return solve(0, arr, 0, dp);
    }
};