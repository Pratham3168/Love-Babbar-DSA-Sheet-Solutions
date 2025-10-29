#include <bits/stdc++.h>
using namespace std;

bool isSubset(vector<int>& a, vector<int>& b) {
    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    int m = a.size(), n = b.size();

    while (i < m && j < n) {
        if (a[i] < b[j]) {
            i++;   // move in a to catch up
        }
        else if (a[i] == b[j]) {
            i++;
            j++;   // matched one element from b
        }
        else {
            // a[i] > b[j] → means b[j] is missing
            return false;
        }
    }

    return (j == n); // all b[] matched
}

int main() {
    vector<int> a = {11, 1, 13, 21, 3, 7};
    vector<int> b = {11, 3, 7, 1};

    if (isSubset(a, b)) cout << "true\n";
    else cout << "false\n";

    return 0;
}