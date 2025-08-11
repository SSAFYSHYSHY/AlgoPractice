#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> v;
    v.reserve(N);

    for (int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        v.push_back({ x, y });
    }

    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return a.second < b.second;
        });

    long long max_time = 0;
    int l = 0, r = N - 1;
    long long scnt = 1, ecnt = 1;

    while (l <= r) {
        max_time = max(max_time, v[l].second + v[r].second);

        if (scnt + 1 > v[l].first) { // s 포인터의 소 수량 다 소진
            l++;
            scnt = 1;
        }
        if (ecnt + 1 > v[r].first) { // e 포인터의 소 수량 다 소진
            r--;
            ecnt = 1;
        }
        scnt++;
        ecnt++;
    }

    cout << max_time << "\n";
    return 0;
}