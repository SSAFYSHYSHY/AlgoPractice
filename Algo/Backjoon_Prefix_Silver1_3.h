#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n + 1, 0), prefix(n + 1, 0);

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        v[a] += 1;

        if (b < n)
            v[b + 1] -= 1;
    }

    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += v[i];
        prefix[i] = sum;
    }

    sort(prefix.begin(), prefix.end());

    int ans = prefix[(n + 1) / 2];
    cout << ans << "\n";
}