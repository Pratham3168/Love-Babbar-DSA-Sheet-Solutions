#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == 0)
            break;

        long long work = 0;
        long long prefix = 0;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;

            prefix += x;
            work += llabs(prefix);
        }

        cout << work << '\n';
    }

    return 0;
}