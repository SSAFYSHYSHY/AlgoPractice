#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

int n, m;
int dx[21];
bool visited[2000001]; // 충분히 크게 (최대 1000 * 10 = 10000 이상 가능)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> dx[i];
    sort(dx, dx + n);

    const int MAX = dx[n - 1] * m;
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q; // (현재 금액, 사용한 우표 수)
    q.push({ 0, 0 });
    visited[0] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cnt == m) continue;

        for (int i = 0; i < n; i++) {
            int next = cur + dx[i];
            if (next > MAX) continue;
            if (!visited[next]) {
                visited[next] = true;
                q.push({ next, cnt + 1 });
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= MAX + 1; i++) {
        if (!visited[i]) break;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}