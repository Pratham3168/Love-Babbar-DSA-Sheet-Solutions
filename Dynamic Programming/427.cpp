/*
    ============================================================
                    LCS OF THREE STRINGS
                    TOP-DOWN DP (MEMOIZATION)
    ============================================================

    Problem:
    Given three strings s1, s2, and s3, find the length of their
    Longest Common Subsequence (LCS).

    Approach:
    We use recursion + memoization.

    State:
        solve(i, j, k) represents the LCS of:
            s1[i...]
            s2[j...]
            s3[k...]

    If all three current characters are equal:
        s1[i] == s2[j] == s3[k]

        Then this character is included in the LCS:

        1 + solve(i+1, j+1, k+1)

    Otherwise, we try skipping one character from each string:

        solve(i+1, j, k)
        solve(i, j+1, k)
        solve(i, j, k+1)

    and take the maximum.

    Base Case:
    If any one of the three strings is exhausted, the LCS length
    becomes 0.

    Time Complexity:
        O(n * m * p)

    Space Complexity:
        O(n * m * p)
        + recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int i, int j, int k,
              string &s1,
              string &s2,
              string &s3,
              vector<vector<vector<int>>> &dp) {

        // Base case
        if (i == s1.length() ||
            j == s2.length() ||
            k == s3.length()) {

            return 0;
        }

        // Already calculated
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        // All three characters are equal
        if (s1[i] == s2[j] && s2[j] == s3[k]) {

            return dp[i][j][k] =
                1 + solve(i + 1, j + 1, k + 1,
                          s1, s2, s3, dp);
        }

        // Skip character from s1
        int op1 = solve(i + 1, j, k,
                        s1, s2, s3, dp);

        // Skip character from s2
        int op2 = solve(i, j + 1, k,
                        s1, s2, s3, dp);

        // Skip character from s3
        int op3 = solve(i, j, k + 1,
                        s1, s2, s3, dp);

        return dp[i][j][k] = max({op1, op2, op3});
    }

    int lcsOf3(string &s1, string &s2, string &s3) {

        int n = s1.length();
        int m = s2.length();
        int p = s3.length();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                m,
                vector<int>(p, -1)
            )
        );

        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};









/*
    ============================================================
                    LCS OF THREE STRINGS
                    BOTTOM-UP DP (TABULATION)
    ============================================================

    Problem:
    Given three strings s1, s2, and s3, find the length of their
    Longest Common Subsequence (LCS).

    Approach:
    We convert the recursive solution into an iterative DP table.

    State:
        dp[i][j][k] represents the LCS length of:

            first i characters of s1
            first j characters of s2
            first k characters of s3

    If the current characters of all three strings are equal:

        dp[i][j][k] = 1 + dp[i-1][j-1][k-1]

    Otherwise, we skip one character from one of the strings:

        dp[i][j][k] = max(
            dp[i-1][j][k],
            dp[i][j-1][k],
            dp[i][j][k-1]
        )

    Base Case:
    If any string has length 0, LCS = 0.

    Time Complexity:
        O(n * m * p)

    Space Complexity:
        O(n * m * p)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int lcsOf3(string &s1, string &s2, string &s3) {

        int n = s1.length();
        int m = s2.length();
        int p = s3.length();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(
                m + 1,
                vector<int>(p + 1, 0)
            )
        );

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                for (int k = 1; k <= p; k++) {

                    // All three characters match
                    if (s1[i - 1] == s2[j - 1] &&
                        s2[j - 1] == s3[k - 1]) {

                        dp[i][j][k] =
                            1 + dp[i - 1][j - 1][k - 1];
                    }

                    // Characters do not match
                    else {

                        dp[i][j][k] = max({
                            dp[i - 1][j][k],
                            dp[i][j - 1][k],
                            dp[i][j][k - 1]
                        });
                    }
                }
            }
        }

        return dp[n][m][p];
    }
};











/*
    ============================================================
                    LCS OF THREE STRINGS
                    SPACE OPTIMIZED DP
                    1D ARRAY + 2D ARRAY
    ============================================================

    Problem:
    Given three strings s1, s2, and s3, find the length of their
    Longest Common Subsequence (LCS).

    Approach:
    The normal bottom-up solution uses a 3D DP table:

        dp[i][j][k]

    While calculating the current i layer, we only need the
    previous i layer.

    Therefore, we remove the i dimension and keep only:

        prev[j][k] -> previous i layer
        curr[j][k] -> current i layer

    We can further optimize the current layer by using a 1D array
    while iterating through k.

    The important values are:

        prev[j][k]       -> previous i layer
        curr[j-1][k]     -> previous j value in current layer
        curr[j][k-1]     -> previous k value in current row
        prev[j-1][k-1]   -> diagonal value

    If all three characters match:

        curr[j][k] = 1 + prev[j-1][k-1]

    Otherwise:

        curr[j][k] = max(
            prev[j][k],
            curr[j-1][k],
            curr[j][k-1]
        )

    Time Complexity:
        O(n * m * p)

    Space Complexity:
        O(m * p)

    The 3D DP table is reduced to two 2D layers.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int lcsOf3(string &s1, string &s2, string &s3) {

        int n = s1.length();
        int m = s2.length();
        int p = s3.length();

        vector<vector<int>> prev(
            m + 1,
            vector<int>(p + 1, 0)
        );

        vector<vector<int>> curr(
            m + 1,
            vector<int>(p + 1, 0)
        );

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                for (int k = 1; k <= p; k++) {

                    // All three characters match
                    if (s1[i - 1] == s2[j - 1] &&
                        s2[j - 1] == s3[k - 1]) {

                        curr[j][k] =
                            1 + prev[j - 1][k - 1];
                    }

                    // Characters do not match
                    else {

                        curr[j][k] = max({
                            prev[j][k],
                            curr[j - 1][k],
                            curr[j][k - 1]
                        });
                    }
                }
            }

            // Current layer becomes previous layer
            prev = curr;

            // Reset current layer
            for (int j = 0; j <= m; j++) {
                fill(curr[j].begin(), curr[j].end(), 0);
            }
        }

        return prev[m][p];
    }
};