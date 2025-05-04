#pragma once
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int arr[201][201];
int prefix[201][201];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // 배열 입력
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            // 누적합 계산
            prefix[i][j] = arr[i][j]
                + prefix[i - 1][j]
                + prefix[i][j - 1]
                - prefix[i - 1][j - 1];
        }
    }

    int maxSum = INT_MIN;

    // 모든 (r1,c1) ~ (r2,c2) 사각형 탐색
    for (int r1 = 1; r1 <= n; ++r1) {
        for (int r2 = r1; r2 <= n; ++r2) {
            for (int c1 = 1; c1 <= m; ++c1) {
                for (int c2 = c1; c2 <= m; ++c2) {
                    int sum = prefix[r2][c2]
                        - prefix[r1 - 1][c2]
                        - prefix[r2][c1 - 1]
                        + prefix[r1 - 1][c1 - 1];
                    maxSum = max(maxSum, sum);
                }
            }
        }
    }

    cout << maxSum << '\n';

    return 0;
}
