#pragma once
#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

// 시간 문자열을 분 단위 정수로 변환
int timeToMin(const string& time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S, E, Q;
    cin >> S >> E >> Q;

    int start = timeToMin(S);
    int end = timeToMin(E);
    int quit = timeToMin(Q);

    unordered_set<string> entered;
    unordered_set<string> exited;

    string line;
    string timeStr, name;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        ss >> timeStr >> name;

        int t = timeToMin(timeStr);

        if (t <= start) {
            entered.insert(name);
        }
        else if (t >= end && t <= quit) {
            exited.insert(name);
        }
    }

    int cnt = 0;
    for (const auto& name : entered) {
        if (exited.find(name) != exited.end()) {
            cnt++;
        }
    }

    cout << cnt << '\n';
}
