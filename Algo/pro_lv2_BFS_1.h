#pragma once
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dir[] = { -1, 1 };

bool InRange(int x, int n) {
    return 0 <= x && x < n;
}

int BFS(int idx, int now, const vector<int>& v, int tar) {
    queue<pair<int, int>> q;
    q.push({ idx, now });
    int cnt = 0;

    while (!q.empty()) {
        int cidx = q.front().first;
        int cnow = q.front().second;
        q.pop();

        if (cidx == v.size()) {
            if (cnow == tar) cnt++;
            continue;
        }

        for (int i = 0; i < 2; i++) {
            int next = cnow + dir[i] * v[cidx];
            q.push({ cidx + 1, next });
        }
    }

    return cnt;
}

int solution(vector<int> numbers, int target) {
    return BFS(0, 0, numbers, target);
}
