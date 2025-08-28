#pragma once
//비트마스크 연습.

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

string arr[51][51];
bool visited[51][51];
int point[51][51];
string dice[7] = { "T", "C", "M", "CM", "MT", "CT", "CMT" };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, t;

struct Node {
    int x, y, cost;
};

struct Node2 {
    int x, y, cost;
    int curr;
};

vector<Node2> player;

void Input() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.length(); j++) {
            arr[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> point[i][j];
        }
    }
}

void Morning() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            point[i][j]++;
        }
    }
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool cmp(Node a, Node b) {
    if (a.cost == b.cost) {
        return a.x < b.x;
        if (a.x == b.x) {
            return a.y < b.y;
        }
    }
    return a.cost > b.cost;
}

bool cmp2(Node2 a, Node2 b) {
    if (a.curr == b.curr) {
        return a.cost > b.cost;

        if (a.cost == b.cost) {
            return a.x < b.x;

            if (a.x == b.x) {
                return a.y < b.y;
            }
        }
    }
    return a.curr < b.curr;
}

void BFS(int x, int y, string s) {
    queue<pair<int, int>> q;

    q.push({ x,y });
    visited[x][y] = true;

    vector<Node> v;
    v.push_back({ x,y,point[x][y] });
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (!InRange(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (arr[nx][ny] != s) continue;

            v.push_back({ nx,ny,point[nx][ny] });
            visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }

    sort(v.begin(), v.end(), cmp);

    // 점수 처리
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) continue;
        else {
            cnt++;
            point[v[i].x][v[i].y]--;
        }
    }
    point[v[0].x][v[0].y] += cnt;

    int idx = 0;
    for (int i = 0; i < 7; i++) {
        if (dice[i] == arr[v[0].x][v[0].y]) {
            idx = i;
            break;
        }
    }

    player.push_back({ v[0].x, v[0].y , point[v[0].x][v[0].y], idx });
    sort(player.begin(), player.end(), cmp2);
}

void Lunch() {
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                BFS(i, j, arr[i][j]);
            }
        }
    }
}

// 문자열 정규화: 중복 제거 + 정렬
string normalize(const string& s) {
    unordered_set<char> set;
    for (char c : s) set.insert(c);

    string res;
    for (char c : set) res.push_back(c);
    sort(res.begin(), res.end());
    return res;
}

// 저녁 행동 처리
void Dinner() {
    bool check[51][51];
    memset(check, false, sizeof(check));

    for (int i = 0; i < player.size(); i++) {
        if (check[player[i].x][player[i].y]) continue; // 공격받으면 스킵

        int x = player[i].cost - 1;
        point[player[i].x][player[i].y] = 1;

        int dir = (player[i].cost) % 4;

        int cx = player[i].x;
        int cy = player[i].y;
        int sx = cx, sy = cy;
        string s = arr[cx][cy];

        while (true) {
            cx += dx[dir];
            cy += dy[dir];

            if (!InRange(cx, cy)) break;
            if (x <= 0) break;
            if (arr[cx][cy] == s) continue;

            int y = point[cx][cy];
            if (x > y) {
                arr[cx][cy] = s;
                point[cx][cy]++;
                x = x - (y + 1);
            }
            else {
                arr[cx][cy] = normalize(arr[cx][cy] + s);
                point[cx][cy] += x;
                x = 0;
            }

            // 다른 플레이어 위치 체크
            for (auto& p : player) {
                if (p.x == cx && p.y == cy) check[cx][cy] = true;
            }
        }
    }

    // 전체 arr 정규화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j].size() > 1) {
                arr[i][j] = normalize(arr[i][j]);
            }
        }
    }
}

void Print() {
    string dice[] = { "T", "C", "M", "CT", "MT", "CM" , "CMT" };
    int ans[7] = { 0, };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == "T") ans[6] += point[i][j];
            else if (arr[i][j] == "C") ans[5] += point[i][j];
            else if (arr[i][j] == "M") ans[4] += point[i][j];
            else if (arr[i][j] == "CT") ans[1] += point[i][j];
            else if (arr[i][j] == "MT") ans[2] += point[i][j];
            else if (arr[i][j] == "CM") ans[3] += point[i][j];
            else if (arr[i][j] == "CMT") ans[0] += point[i][j];
        }
    }

    for (int i = 0; i < 7; i++) cout << ans[i] << " ";
    cout << "\n";

    player.clear();
}

int main() {
    Input();

    while (t--) {
        Morning();
        Lunch();
        Dinner();
        Print();
    }
}
