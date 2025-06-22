#pragma once
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, ans = 0;
    map<int, int> a, b;
    cin >> n;

    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        a[x]++;
        b[y]++;
    }

    for (auto it = a.begin(); it != a.end(); it++) {
        if (it->second >= 2) {
            ans++;
        }
    }

    for (auto it = b.begin(); it != b.end(); it++) {
        if (it->second >= 2) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}