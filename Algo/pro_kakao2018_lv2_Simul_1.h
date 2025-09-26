#pragma once
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

char arr[31][31];
bool visited[31][31];
int N, M;

bool InRange(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

bool Calc(int sx, int sy, char c) {
    for (int i = sx; i < sx + 2; i++) {
        for (int j = sy; j < sy + 2; j++) {
            if (!InRange(i, j)) return false;
            if (arr[i][j] != c) return false;
        }
    }

    return true;
}

void Draw(int sx, int sy) {
    for (int i = sx; i < sx + 2; i++) {
        for (int j = sy; j < sy + 2; j++) {
            visited[i][j] = true;
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    N = n, M = m;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            arr[i][j] = board[i][j];
        }
    }


    while (1) {
        bool flag = true;
        memset(visited, false, sizeof(visited));

        //2X2사각형 체크 처리.
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (arr[i][j] == '.') continue;
                if (Calc(i, j, arr[i][j])) {
                    Draw(i, j);
                    flag = false;
                }
            }
        }

        //아무것도 체크하지 않았으므로 더 이상 점수 획득 불능.
        if (flag) break;

        //체크처리 된 것 삭제.
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j]) {
                    arr[i][j] = '.';
                    cnt++;
                }
            }
        }
        answer += cnt;

        //중력 적용.
        char new_arr[31][31];
        for (int j = 0; j < m; j++) {
            int now_num = n - 1;

            for (int i = n - 1; i >= 0; i--) {
                if (arr[i][j] != '.') {
                    new_arr[now_num][j] = arr[i][j];
                    now_num--;
                }
            }

            while (now_num >= 0) {
                new_arr[now_num][j] = '.';
                now_num--;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = new_arr[i][j];
            }
        }
    }

    return answer;
}