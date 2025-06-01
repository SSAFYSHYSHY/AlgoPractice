#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int N, H, L;
    cin >> N >> H >> L;

    vector<int> horrorIndex(N, INT_MAX); // 공포 지수 처음에는 전부 무한대
    vector<vector<int>> adj(N); // 유사 영화 관계
    queue<int> q;

    for (int i = 0; i < H; ++i) {
        int h;
        cin >> h;
        horrorIndex[h] = 0;
        q.push(h);
    }

    for (int i = 0; i < L; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : adj[cur]) {
            if (horrorIndex[next] > horrorIndex[cur] + 1) {
                horrorIndex[next] = horrorIndex[cur] + 1;
                q.push(next);
            }
        }
    }

    int maxHI = -1, answerID = -1;
    for (int i = 0; i < N; ++i) {
        if (horrorIndex[i] > maxHI) {
            maxHI = horrorIndex[i];
            answerID = i;
        }
    }

    cout << answerID << endl;

    return 0;
}
#pragma once
