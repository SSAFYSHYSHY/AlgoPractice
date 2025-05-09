#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, k, ans = 0;

bool Calc(const vector<long long>& v, long long mid) {
    int s = n;

    for (int i = 0; i < k; i++) {
        if (s - mid <= 1) {
            return true;
        }

        int next = s - mid;

        while (!v[next]) {
            next++;

            if (next == n) {
                return false;
            }
        }

        s = next;
    }
    return false;
}

int main() {
    cin >> n >> k;

    vector<long long> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    long long l = 1, r = n;

    while (l <= r) {
        long long mid = (l + r) / 2;

        if (Calc(v, mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
}
