#pragma once
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ť�� ���� ����: ���� ����, ����� Ƽ�� ��, ���, used �迭
struct State {
    string curr;
    int usedCount;
    vector<string> path;
    vector<bool> used;
};

vector<string> solution(vector<vector<string>> tickets) {
    // ������ ����
    sort(tickets.begin(), tickets.end());

    queue<State> q;
    vector<string> result;

    // ������ "ICN"
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

        // ��� Ƽ���� ��������� �� �ĺ�
        if (s.usedCount == tickets.size()) {
            return s.path; // BFS�� ���� ���� ������ �� ���������� ����
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

    return {}; // ���� ó��
}