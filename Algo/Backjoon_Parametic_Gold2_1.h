#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

struct Point {
    int x, y;
};

int n, k;
vector<Point> points;
bool visited[1002];

// 현재 mid 용량으로 도달 가능한지 검사
bool canReach(int maxFuel) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q; // pair<현재 위치 인덱스, 사용한 경유 횟수>
    q.push(make_pair(0, 0));
    visited[0] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int curIndex = current.first;
        int fuelUsed = current.second;

        if (curIndex == n + 1) {
            // 도착지 도달
            return fuelUsed <= k + 1;
        }

        for (int i = 0; i <= n + 1; i++) {
            if (visited[i]) continue;

            int dx = points[curIndex].x - points[i].x;
            int dy = points[curIndex].y - points[i].y;
            double distance = sqrt(dx * dx + dy * dy);

            if (distance <= maxFuel * 10.0) {
                visited[i] = true;
                q.push(make_pair(i, fuelUsed + 1));
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> k;
    points.push_back({ 0, 0 }); // 출발점 S

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({ x, y });
    }

    points.push_back({ 10000, 10000 }); // 도착점 T

    int left = 0;
    int right = 14150;
    int answer = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canReach(mid)) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";

    return 0;
}
