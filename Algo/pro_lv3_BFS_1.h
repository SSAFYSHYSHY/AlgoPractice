#pragma once
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 큐에 넣을 상태: 현재 공항, 사용한 티켓 수, 경로, used 배열
struct State {
    string curr;
    int usedCount;
    vector<string> path;
    vector<bool> used;
};

vector<string> solution(vector<vector<string>> tickets) {
    // 사전순 정렬
    sort(tickets.begin(), tickets.end());

    queue<State> q;
    vector<string> result;

    // 시작점 "ICN"
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == "ICN") {
            vector<string> initialPath = { "ICN", tickets[i][1] };
            vector<bool> used(tickets.size(), false);
            used[i] = true;
            q.push({ "ICN", 1, initialPath, used });
        }
    }

    while (!q.empty()) {
        State s = q.front();
        q.pop();

        // 모든 티켓을 사용했으면 답 후보
        if (s.usedCount == tickets.size()) {
            return s.path; // BFS라서 가장 먼저 나오는 게 사전순으로 빠름
        }

        for (int i = 0; i < tickets.size(); i++) {
            if (!s.used[i] && tickets[i][0] == s.path.back()) {
                vector<string> nextPath = s.path;
                nextPath.push_back(tickets[i][1]);

                vector<bool> nextUsed = s.used;
                nextUsed[i] = true;

                q.push({ tickets[i][0], s.usedCount + 1, nextPath, nextUsed });
            }
        }
    }

    return {}; // 예외 처리
}