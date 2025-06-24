#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N, B;
        cin >> N >> B;
        if (N == -1 && B == -1) break;

        vector<int> population(N);
        int maxPop = 0;
        for (int i = 0; i < N; ++i) {
            cin >> population[i];
            maxPop = max(maxPop, population[i]);
        }

        // 이분 탐색: 한 투표함당 최대 사람 수를 이분 탐색
        int left = 1, right = maxPop;
        int answer = maxPop;

        while (left <= right) {
            int mid = (left + right) / 2;

            long long boxesNeeded = 0;
            for (int i = 0; i < N; ++i) {
                // 올림(ceil) 효과: (인구 + mid - 1) / mid
                boxesNeeded += (population[i] + mid - 1) / mid;
            }

            if (boxesNeeded <= B) {
                answer = mid;
                right = mid - 1; // 더 줄일 수 있는지 확인
            }
            else {
                left = mid + 1; // mid로는 부족하므로 증가
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
