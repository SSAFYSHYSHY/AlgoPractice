#pragma once
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[201] = { false, };

void BFS(int start, const vector<vector<int>>& com) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cx = q.front();
        q.pop();

        for (int i = 0; i < com.size(); i++) {
            if (!visited[i] && com[cx][i] == 1) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            BFS(i, computers);
            answer++;
        }
    }

    return answer;
}