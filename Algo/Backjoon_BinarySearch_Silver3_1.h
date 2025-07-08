#pragma once
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long l = 1, r = 10000000000000000LL, ans = 0;
        while (l <= r) {
            long long mid = (l + r) / 2;

            if (mid <= n && mid <= (2 * n) / (mid + 1)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
