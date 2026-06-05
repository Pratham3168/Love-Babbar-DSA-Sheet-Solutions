#include <iostream>
#include <vector>
using namespace std;

int solve(int h, int a, int last , vector<vector<vector<int>>>& dp) {
    //base case
    if(h<=0 || a<=0) return 0;

    if(dp[h][a][last] != -1) return dp[h][a][last];

    if(last == 0){
        return dp[h][a][last] =  1 + max(solve(h-5,a-10,1,dp) , solve(h-20,a+5,2,dp));
    }
    else if(last == 1){
        return dp[h][a][last] = 1 + max(solve(h+3,a+2,0,dp) , solve(h-20,a+5,2,dp));
    }
    else{
        return dp[h][a][last] = 1 + max(solve(h+3,a+2,0,dp) , solve(h-5,a-10,1,dp));
    }

}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int H, A;
        cin >> H >> A;
        vector<vector<vector<int>>> dp(
            2005,
            vector<vector<int>>(2005, vector<int>(3, -1))
        );

        int ans = max(
            solve(H + 3, A + 2, 0,dp),      // Air
            max(solve(H - 5, A - 10, 1,dp),     // Water
            solve(H - 20, A + 5, 2,dp))    // Fire
        );

        cout << ans << '\n';
    }

    return 0;
}