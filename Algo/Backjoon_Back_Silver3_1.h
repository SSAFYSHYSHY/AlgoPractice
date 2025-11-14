#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int W, C, F;
        cin >> W >> C >> F;

        vector<int> w(N), c(N), f(N);
        for (int i = 0; i < N; i++) {
            cin >> w[i] >> c[i] >> f[i];
        }

        int ans = 1e9;   // 매우 큰 값으로 시작

        // 부분집합 완전탐색: 0 ~ (1<<N)-1
        for (int mask = 0; mask < (1 << N); mask++) {
            int sumW = 0, sumC = 0, sumF = 0;
            int cnt = 0;

            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    sumW += w[i];
                    sumC += c[i];
                    sumF += f[i];
                    cnt++;
                }
            }

            if (sumW >= W && sumC >= C && sumF >= F) {
                ans = min(ans, cnt);
            }
        }

        if (ans == 1e9) cout << "game over\n";
        else cout << ans << "\n";
    }

    return 0;
}