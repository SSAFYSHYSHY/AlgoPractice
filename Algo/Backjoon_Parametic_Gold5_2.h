#pragma once
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> cost;

bool isPossible(int maxCost) {
    vector<bool> ok(N);
    for (int i = 0; i < N; ++i) {
        ok[i] = cost[i] <= maxCost;
    }

    // 슬라이딩 윈도우로 연속된 K개 구간 중 수락된 의뢰가 하나라도 있는지 확인
    int cnt = 0;
    for (int i = 0; i < K; ++i) {
        if (ok[i]) cnt++;
    }
    if (cnt == 0) return false;

    for (int i = K; i < N; ++i) {
        if (ok[i - K]) cnt--;
        if (ok[i]) cnt++;
        if (cnt == 0) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    cost.resize(N);
    int low = 1, high = 1e9, ans = 1e9;

    for (int i = 0; i < N; ++i) {
        cin >> cost[i];
    }

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
