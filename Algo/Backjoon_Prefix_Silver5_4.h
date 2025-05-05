#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dist(N + 1);
    vector<int> prefix(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> dist[i];
        prefix[i] = prefix[i - 1] + dist[i];
    }

    int K;
    cin >> K;

    bool possible = true;
    int maxCity = 0;
    for (int i = 0; i < K; ++i) {
        int a, t;
        cin >> a >> t;

        int arrivalTime = prefix[a];

        if (arrivalTime > t) {
            possible = false;
        }

        maxCity = max(maxCity, a);
    }

    if (!possible) {
        cout << -1 << "\n";
    }
    else {
        cout << 2 * prefix[maxCity] << "\n";
    }

    return 0;
}
