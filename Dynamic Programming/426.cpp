/*
    ============================================================
                    LONGEST COMMON SUBSEQUENCE
                    BOTTOM-UP DP (TABULATION)
    ============================================================

    Problem:
    Given two strings s1 and s2, find the length of their
    Longest Common Subsequence (LCS).

    Approach:
    We convert the recursive solution into an iterative DP table.

    State:
        dp[i][j] represents the LCS length of:

            first i characters of s1
            first j characters of s2

    If the current characters are equal:

        s1[i-1] == s2[j-1]

        dp[i][j] = 1 + dp[i-1][j-1]

    Otherwise:

        dp[i][j] = max(
            dp[i-1][j],
            dp[i][j-1]
        )

    Base Case:
    If either string has length 0, LCS = 0.

    Time Complexity:
        O(n * m)

    Space Complexity:
        O(n * m)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int lcs(string &s1, string &s2) {

        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                // Characters match
                if (s1[i - 1] == s2[j - 1]) {

                    dp[i][j] =
                        1 + dp[i - 1][j - 1];
                }

                // Characters do not match
                else {

                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
                }
            }
        }

        return dp[n][m];
    }
};





/*
    ============================================================
                    LONGEST COMMON SUBSEQUENCE
                    SPACE OPTIMIZED DP
                    USING 1D ARRAYS
    ============================================================

    Problem:
    Given two strings s1 and s2, find the length of their
    Longest Common Subsequence (LCS).

    Approach:
    The normal bottom-up solution uses a 2D DP table:

        dp[i][j]

    While calculating row i, we only need values from:

        - Previous row
        - Current row

    Therefore, the 2D table can be reduced to two 1D arrays:

        prev -> previous row
        curr -> current row

    If the characters match:

        curr[j] = 1 + prev[j-1]

    Otherwise:

        curr[j] = max(
            prev[j],
            curr[j-1]
        )

    After completing each row:

        prev = curr

    Time Complexity:
        O(n * m)

    Space Complexity:
        O(m)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int lcs(string &s1, string &s2) {

        int n = s1.length();
        int m = s2.length();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                // Characters match
                if (s1[i - 1] == s2[j - 1]) {

                    curr[j] =
                        1 + prev[j - 1];
                }

                // Characters do not match
                else {

                    curr[j] = max(
                        prev[j],
                        curr[j - 1]
                    );
                }
            }

            // Current row becomes previous row
            prev = curr;

            // Reset current row
            fill(curr.begin(), curr.end(), 0);
        }

        return prev[m];
    }
};