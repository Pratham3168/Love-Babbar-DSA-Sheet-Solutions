#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int w, h, n;
        cin >> w >> h >> n;

        vector<int> x(n + 2);
        vector<int> y(n + 2);

        x[0] = 0;
        y[0] = 0;

        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }

        x[n + 1] = w + 1;
        y[n + 1] = h + 1;

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int Xgap = 0;
        int Ygap = 0;

        int i = 0;
        int j = 1;

        while (j < (int)x.size()) {
            Xgap = max(Xgap, x[j] - x[i] - 1);
            Ygap = max(Ygap, y[j] - y[i] - 1);

            i++;
            j++;
        }

        cout << Xgap * Ygap << '\n';
    }

    return 0;
}