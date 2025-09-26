#pragma once
//2차원 누적합.
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int arr[1001][1001];
int temp[1001][1001];
int N, M;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    N = board.size();
    M = board[0].size();

    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            arr[i][j] = board[i][j];
        }
    }

    for (auto& s : skill) {
        int type = s[0];
        int sx = s[1], sy = s[2], ex = s[3], ey = s[4], degree = s[5];
        int val = (type == 1 ? -degree : degree);

        temp[sx][sy] += val;
        temp[ex + 1][sy] -= val;
        temp[sx][ey + 1] -= val;
        temp[ex + 1][ey + 1] += val;
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            temp[i][j] += temp[i][j - 1];
        }
    }

    for (int j = 0; j <= M; j++) {
        for (int i = 1; i <= N; i++) {
            temp[i][j] += temp[i - 1][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] + temp[i][j] > 0) answer++;
        }
    }

    return answer;
}