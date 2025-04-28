#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<char> v;           // ���� ���
vector<char> result;      // ���� ���� ���
char arr[11][11];
int n, m, ans = 11;

char dir[] = { 'U','D','L','R' };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int r_x, r_y, b_x, b_y;

void Input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j];
            if (arr[i][j] == 'R') {
                r_x = i;
                r_y = j;
                arr[i][j] = '.';
            }
            if (arr[i][j] == 'B') {
                b_x = i;
                b_y = j;
                arr[i][j] = '.';
            }
        }
    }
}

void Move(int& x, int& y, int dir_idx, int& cnt) {
    while (true) {
        if (arr[x + dx[dir_idx]][y + dy[dir_idx]] == '#' || arr[x][y] == 'O') break;
        x += dx[dir_idx];
        y += dy[dir_idx];
        cnt++;
    }
}

int BFS(vector<char> dirs) {
    int red_x = r_x, red_y = r_y;
    int blue_x = b_x, blue_y = b_y;

    for (int d = 0; d < dirs.size(); d++) {
        int dir_idx;
        if (dirs[d] == 'U') dir_idx = 0;
        else if (dirs[d] == 'D') dir_idx = 1;
        else if (dirs[d] == 'L') dir_idx = 2;
        else dir_idx = 3;

        int r_cnt = 0, b_cnt = 0;

        Move(red_x, red_y, dir_idx, r_cnt);
        Move(blue_x, blue_y, dir_idx, b_cnt);

        // �Ķ� ������ ���ۿ� ������ ����
        if (arr[blue_x][blue_y] == 'O') return 11;

        // ���� ������ ���ۿ� ������ ����
        if (arr[red_x][red_y] == 'O') return d + 1;

        // ���� ���� ĭ�� ���� �� ���� �� �� ���� �̵��� ������ �� ĭ �ڷ�
        if (red_x == blue_x && red_y == blue_y) {
            if (r_cnt > b_cnt) {
                red_x -= dx[dir_idx];
                red_y -= dy[dir_idx];
            }
            else {
                blue_x -= dx[dir_idx];
                blue_y -= dy[dir_idx];
            }
        }
    }

    return 11; // ����
}

void Back(int now, int tar, vector<char> v) {
    if (now == tar) {
        int res = BFS(v);
        if (res <= 10) {
            if (res < ans) {
                ans = res;
                result = v; // ���� ��θ� ����
                return;
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        v.push_back(dir[i]);
        Back(now + 1, tar, v);
        v.pop_back();
    }
}

int main() {
    Input();

    Back(0, 10, v);

    if (ans == 11) cout << -1;
    else {
        cout << ans << "\n";
        for (int i = 0; i < ans; i++) {  // ���� ��� ���
            cout << result[i];
        }
    }

    return 0;
}
