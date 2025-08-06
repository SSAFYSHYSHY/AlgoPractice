#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> hi(N), arc(M);

    for (int i = 0; i < N; ++i) cin >> hi[i];
    for (int i = 0; i < M; ++i) cin >> arc[i];

    sort(arc.begin(), arc.end());

    long long win_hi = 0, win_arc = 0, draw = 0;

    for (int i = 0; i < N; ++i) {
        int win = lower_bound(arc.begin(), arc.end(), hi[i]) - arc.begin();

        int same = upper_bound(arc.begin(), arc.end(), hi[i]) - lower_bound(arc.begin(), arc.end(), hi[i]);

        int lose = M - win - same;

        win_hi += win;
        draw += same;
        win_arc += lose;
    }

    cout << win_hi << " " << win_arc << " " << draw << '\n';
    return 0;
}