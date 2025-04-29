#pragma once
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 행에 대해 슬라이딩 윈도우로 K개씩 최대값 구하는 함수
vector<vector<int>> row_max(const vector<vector<int>>& M, int N, int K) {
    vector<vector<int>> rowMax(N, vector<int>(N - K + 1));
    for (int i = 0; i < N; ++i) {
        deque<int> dq;
        for (int j = 0; j < N; ++j) {
            // dq 앞에서 범위 벗어난 인덱스 제거
            if (!dq.empty() && dq.front() <= j - K)
                dq.pop_front();
            // dq 뒤에서 현재 값보다 작은 값들 제거
            while (!dq.empty() && M[i][dq.back()] <= M[i][j])
                dq.pop_back();
            dq.push_back(j);
            if (j >= K - 1)
                rowMax[i][j - K + 1] = M[i][dq.front()];
        }
    }
    return rowMax;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int N, K, C, X;
        cin >> N >> K >> C >> X;
        vector<int> A(N + 1), B(N + 1); // 1-indexed로 사용
        for (int i = 1; i <= N; ++i) cin >> A[i];
        for (int i = 1; i <= N; ++i) cin >> B[i];

        // 행렬 M 생성
        vector<vector<int>> M(N, vector<int>(N));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                M[i - 1][j - 1] = (A[i] * i + B[j] * j + C) % X;
            }
        }

        // 1단계: 각 행별로 슬라이딩 윈도우 최대값 구하기
        vector<vector<int>> rowMax = row_max(M, N, K);

        // 2단계: 각 열별로 슬라이딩 윈도우 적용해 KxK 블록 최대값 구하기
        long long totalSum = 0;
        for (int j = 0; j <= N - K; ++j) {
            deque<int> dq;
            for (int i = 0; i < N; ++i) {
                if (!dq.empty() && dq.front() <= i - K)
                    dq.pop_front();
                while (!dq.empty() && rowMax[dq.back()][j] <= rowMax[i][j])
                    dq.pop_back();
                dq.push_back(i);
                if (i >= K - 1)
                    totalSum += rowMax[dq.front()][j];
            }
        }

        cout << "Case #" << test_case << ": " << totalSum << '\n';
    }

    return 0;
}
