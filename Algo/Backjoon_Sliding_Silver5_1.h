#pragma once
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// �࿡ ���� �����̵� ������� K���� �ִ밪 ���ϴ� �Լ�
vector<vector<int>> row_max(const vector<vector<int>>& M, int N, int K) {
    vector<vector<int>> rowMax(N, vector<int>(N - K + 1));
    for (int i = 0; i < N; ++i) {
        deque<int> dq;
        for (int j = 0; j < N; ++j) {
            // dq �տ��� ���� ��� �ε��� ����
            if (!dq.empty() && dq.front() <= j - K)
                dq.pop_front();
            // dq �ڿ��� ���� ������ ���� ���� ����
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
        vector<int> A(N + 1), B(N + 1); // 1-indexed�� ���
        for (int i = 1; i <= N; ++i) cin >> A[i];
        for (int i = 1; i <= N; ++i) cin >> B[i];

        // ��� M ����
        vector<vector<int>> M(N, vector<int>(N));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                M[i - 1][j - 1] = (A[i] * i + B[j] * j + C) % X;
            }
        }

        // 1�ܰ�: �� �ະ�� �����̵� ������ �ִ밪 ���ϱ�
        vector<vector<int>> rowMax = row_max(M, N, K);

        // 2�ܰ�: �� ������ �����̵� ������ ������ KxK ��� �ִ밪 ���ϱ�
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
