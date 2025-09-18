#pragma once
//https://www.codetree.ai/ko/frequent-problems/samsung-sw/problems/hide-and-seek/description
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int x, y, dir;
    bool flag, life;
};

int n, m, h, k, sx = 0, sy = 0;
vector<Node> v;
int arr[101][101];

int dx[] = { -1,0,1,0 }; // ��, ��, ��, ��
int dy[] = { 0,1,0,-1 };

int sdir = 0;     // ���� ���� (0=��,1=��,2=��,3=��)
int slen = 1;     // ���� �̵��ؾ� �� ĭ ��
int scnt = 0;     // ���ݱ��� �̵��� ĭ ��
int srepeat = 0;  // ���� ���� �� �� ����ߴ���
bool sflag = false; // false=ȸ����, true=�ݴ� ȸ����

void Input() {
    cin >> n >> m >> h >> k;

    sx = n / 2;
    sy = n / 2;

    for (int i = 0; i < m; i++) {
        int x, y, dir;
        cin >> x >> y >> dir;
        x--; y--;

        // ������ ���� (1=��, 2=��)
        if (dir == 1) dir = 1;
        else if (dir == 2) dir = 2;

        v.push_back({ x, y, dir, false, true });
    }

    for (int i = 0; i < h; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        arr[x][y] = 2; // ���� ǥ��
    }
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

// ������ �̵�
void Move() {
    for (int i = 0; i < v.size(); i++) {
        int cx = v[i].x;
        int cy = v[i].y;
        int cdir = v[i].dir;

        // �������� ����ư �Ÿ��� 3 �ʰ��� �̵� �� ��
        if ((abs(sx - cx) + abs(sy - cy) > 3)) continue;

        int nx = cx + dx[cdir];
        int ny = cy + dy[cdir];

        if (InRange(nx, ny)) {
            // ���� ��ġ�� �̵� �Ұ� �� ���ڸ� ����
            if (nx == sx && ny == sy) {
                nx = cx;
                ny = cy;
            }
            if (arr[nx][ny] == 2) v[i] = { nx, ny, cdir, true, true };
            else v[i] = { nx, ny, cdir, false, true };
        }
        else {
            // ���� ����
            cdir = (cdir + 2) % 4;
            nx = cx + dx[cdir];
            ny = cy + dy[cdir];
            if (arr[nx][ny] == 2) v[i] = { nx, ny, cdir, true, true };
            else v[i] = { nx, ny, cdir, false, true };
        }
    }
}

// ������ ���� �������� 3ĭ �ȿ� �ִ� ������ ���
int Calc(int dir) {
    int cnt = 0;

    // ���� �ڱ� ĭ ����
    for (int j = 0; j < v.size(); j++) {
        if (!v[j].life) continue;
        if (v[j].flag) continue;
        if (v[j].x == sx && v[j].y == sy) {
            cnt++;
            v[j].life = false;
        }
    }

    // ������ 3ĭ
    int cx = sx, cy = sy;
    for (int i = 0; i < 3; i++) {
        cx += dx[dir];
        cy += dy[dir];
        if (!InRange(cx, cy)) break;

        for (int j = 0; j < v.size(); j++) {
            if (!v[j].life) continue;
            if (v[j].flag) continue;
            if (v[j].x == cx && v[j].y == cy) {
                cnt++;
                v[j].life = false;
            }
        }
    }

    // ��Ƴ��� �����ڸ� �ٽ� ����
    vector<Node> temp_v;
    for (auto& p : v) if (p.life) temp_v.push_back(p);
    v = temp_v;

    return cnt;
}

// ���� �̵� (ȸ���� / �ݴ� ȸ����)
int Move2() {
    sx += dx[sdir];
    sy += dy[sdir];
    scnt++;

    // �� ���� �������� ���� ��ȯ
    if (scnt == slen) {
        scnt = 0;
        sdir = (sflag ? (sdir + 3) % 4 : (sdir + 1) % 4);
        srepeat++;

        if (srepeat == 2) {
            srepeat = 0;
            if (!sflag) slen++;
            else slen = max(1, slen - 1); // 0 ���� ����
        }
    }

    // (0,0) ���� �� �ݴ� ȸ���� ����
    if (sx == 0 && sy == 0) {
        sflag = true;
        sdir = 2; // �Ʒ����� ����
        slen = n - 1;
        scnt = 0;
        srepeat = 0;
    }
    // �߾� ���� �� ȸ���� �����
    else if (sx == n / 2 && sy == n / 2) {
        sflag = false;
        sdir = 0; // ������ ����
        slen = 1;
        scnt = 0;
        srepeat = 0;
    }

    return sdir;
}

int main() {
    Input();

    int ans = 0, sum = 0;
    for (int i = 1; i <= k; i++) {
        Move();          // ������ �̵�
        int dir = Move2(); // ���� �̵�
        sum = Calc(dir);  // ������ ���
        ans += sum * i;
    }

    cout << ans;
}
