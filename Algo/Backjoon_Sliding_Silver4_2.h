#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int M, N, K, W;
    cin >> M >> N >> K >> W;

    vector<vector<int>> A(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    // 결과 B는 크기가 (M - W + 1) x (N - W + 1)
    vector<vector<int>> B(M - W + 1, vector<int>(N - W + 1));

    for (int i = 0; i <= M - W; ++i) {
        for (int j = 0; j <= N - W; ++j) {
            vector<int> window;

            // W x W 영역 수집
            for (int x = 0; x < W; ++x) {
                for (int y = 0; y < W; ++y) {
                    window.push_back(A[i + x][j + y]);
                }
            }

            // 중앙값 구하기
            sort(window.begin(), window.end());
            B[i][j] = window[window.size() / 2];
        }
    }

    // 출력
    for (int i = 0; i < B.size(); ++i) {
        for (int j = 0; j < B[0].size(); ++j) {
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}