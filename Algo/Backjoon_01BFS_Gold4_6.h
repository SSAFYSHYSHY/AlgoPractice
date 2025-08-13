#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct State {
    int t, tree, h;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<vector<bool>> holes(N, vector<bool>(21, false));
    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M;
        for (int j = 0; j < M; ++j) {
            int h;
            cin >> h;
            holes[i][h] = true;
        }
    }

    vector<vector<int>> minT(N + 1, vector<int>(21, INT_MAX));
    deque<State> dq;

    dq.push_front({ 0, 0, 1 }); // {T 사용 횟수, 현재 나무, 현재 높이}
    minT[0][1] = 0;

    while (!dq.empty()) {
        int usedT = dq.front().t;
        int currentTree = dq.front().tree;
        int currentH = dq.front().h;
        dq.pop_front();

        if (currentTree == N) {
            cout << usedT << '\n';
            return 0;
        }
        if (currentTree >= N) continue;

        int nextTree = currentTree + 1;

        auto push0 = [&](int nh) {
            if (holes[currentTree][nh] && minT[nextTree][nh] > usedT) {
                minT[nextTree][nh] = usedT;
                dq.push_front({ usedT, nextTree, nh });
            }
            };

        auto push1 = [&](int nh) {
            if (holes[currentTree][nh] && minT[nextTree][nh] > usedT + 1) {
                minT[nextTree][nh] = usedT + 1;
                dq.push_back({ usedT + 1, nextTree, nh });
            }
            };

        // O, A, B, C 기능은 비용 0
        push0(currentH); // O
        if (currentH + 1 <= 20) push0(currentH + 1); // A
        int nextB = (currentH >= 10) ? 20 : min(20, currentH * 2);
        push0(nextB); // B
        if (currentH - 1 >= 1) push0(currentH - 1); // C

        // T 기능은 비용 1
        if (usedT < K) {
            for (int h = 1; h <= 20; ++h) {
                push1(h);
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
