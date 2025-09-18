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

int dx[] = { -1,0,1,0 }; // 상, 우, 하, 좌
int dy[] = { 0,1,0,-1 };

int sdir = 0;     // 술래 방향 (0=상,1=우,2=하,3=좌)
int slen = 1;     // 현재 이동해야 할 칸 수
int scnt = 0;     // 지금까지 이동한 칸 수
int srepeat = 0;  // 같은 길이 몇 번 사용했는지
bool sflag = false; // false=회오리, true=반대 회오리

void Input() {
    cin >> n >> m >> h >> k;

    sx = n / 2;
    sy = n / 2;

    for (int i = 0; i < m; i++) {
        int x, y, dir;
        cin >> x >> y >> dir;
        x--; y--;

        // 도망자 방향 (1=우, 2=하)
        if (dir == 1) dir = 1;
        else if (dir == 2) dir = 2;

        v.push_back({ x, y, dir, false, true });
    }

    for (int i = 0; i < h; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        arr[x][y] = 2; // 나무 표시
    }
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

// 도망자 이동
void Move() {
    for (int i = 0; i < v.size(); i++) {
        int cx = v[i].x;
        int cy = v[i].y;
        int cdir = v[i].dir;

        // 술래와의 맨해튼 거리가 3 초과면 이동 안 함
        if ((abs(sx - cx) + abs(sy - cy) > 3)) continue;

        int nx = cx + dx[cdir];
        int ny = cy + dy[cdir];

        if (InRange(nx, ny)) {
            // 술래 위치면 이동 불가 → 제자리 유지
            if (nx == sx && ny == sy) {
                nx = cx;
                ny = cy;
            }
            if (arr[nx][ny] == 2) v[i] = { nx, ny, cdir, true, true };
            else v[i] = { nx, ny, cdir, false, true };
        }
        else {
            // 방향 반전
            cdir = (cdir + 2) % 4;
            nx = cx + dx[cdir];
            ny = cy + dy[cdir];
            if (arr[nx][ny] == 2) v[i] = { nx, ny, cdir, true, true };
            else v[i] = { nx, ny, cdir, false, true };
        }
    }
}

// 술래가 보는 방향으로 3칸 안에 있는 도망자 잡기
int Calc(int dir) {
    int cnt = 0;

    // 술래 자기 칸 포함
    for (int j = 0; j < v.size(); j++) {
        if (!v[j].life) continue;
        if (v[j].flag) continue;
        if (v[j].x == sx && v[j].y == sy) {
            cnt++;
            v[j].life = false;
        }
    }

    // 앞으로 3칸
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

    // 살아남은 도망자만 다시 저장
    vector<Node> temp_v;
    for (auto& p : v) if (p.life) temp_v.push_back(p);
    v = temp_v;

    return cnt;
}

// 술래 이동 (회오리 / 반대 회오리)
int Move2() {
    sx += dx[sdir];
    sy += dy[sdir];
    scnt++;

    // 한 구간 끝났으면 방향 전환
    if (scnt == slen) {
        scnt = 0;
        sdir = (sflag ? (sdir + 3) % 4 : (sdir + 1) % 4);
        srepeat++;

        if (srepeat == 2) {
            srepeat = 0;
            if (!sflag) slen++;
            else slen = max(1, slen - 1); // 0 이하 방지
        }
    }

    // (0,0) 도달 → 반대 회오리 시작
    if (sx == 0 && sy == 0) {
        sflag = true;
        sdir = 2; // 아래부터 시작
        slen = n - 1;
        scnt = 0;
        srepeat = 0;
    }
    // 중앙 도달 → 회오리 재시작
    else if (sx == n / 2 && sy == n / 2) {
        sflag = false;
        sdir = 0; // 위부터 시작
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
        Move();          // 도망자 이동
        int dir = Move2(); // 술래 이동
        sum = Calc(dir);  // 도망자 잡기
        ans += sum * i;
    }

    cout << ans;
}
