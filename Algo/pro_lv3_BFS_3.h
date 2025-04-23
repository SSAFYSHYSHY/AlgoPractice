#pragma once
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[51] = { false, };

bool Calc(string a, string b) {
    int diff = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return false;
    }
    return diff == 1;
}

int BFS(string s, string e, const vector<string>& v) {
    queue<pair<string, int>> q;
    q.push({ s, 0 });

    while (!q.empty()) {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == e) {
            return cnt;
        }

        for (int i = 0; i < v.size(); i++) {
            string next = v[i];

            //두 쌍 중에 딱 한 글자만 틀리면.
            if (Calc(cur, next) && !visited[i]) {
                q.push({ next, cnt + 1 });
                visited[i] = true;
            }
        }
    }

    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    answer = BFS(begin, target, words);

    return answer;
}