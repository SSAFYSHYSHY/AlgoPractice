#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> prefix(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }

    for (int i = 0; i < n; i++) {
        long long b;
        cin >> b;

        int idx = lower_bound(prefix.begin(), prefix.end(), b) - prefix.begin();

        if (idx > m)
            cout << "Go away!\n";
        else
            cout << idx << '\n';
    }
    return 0;
}