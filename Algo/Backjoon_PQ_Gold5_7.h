#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct Info {
    int arrive, leave;
};

// 도착 시간 오름차순 (도착시간 같으면 퇴근시간 빠른 순)
struct CmpArrive {
    bool operator()(const Info& a, const Info& b) const {
        if (a.arrive == b.arrive) return a.leave > b.leave;
        return a.arrive > b.arrive;
    }
};

// 퇴근 시간 오름차순 (퇴근시간 같으면 도착시간 빠른 순)
struct CmpLeave {
    bool operator()(const Info& a, const Info& b) const {
        if (a.leave == b.leave) return a.arrive > b.arrive;
        return a.leave > b.leave;
    }
};

int toMillis(const string& s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int sec = stoi(s.substr(6, 2));
    int ms = stoi(s.substr(9));

    return h * 3600000 + m * 60000 + sec * 1000 + ms;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<Info, vector<Info>, CmpArrive> arrivals;
    priority_queue<Info, vector<Info>, CmpLeave> station;

    // 입력
    for (int i = 0; i < n; i++) {
        string come, leave;
        cin >> come >> leave;
        arrivals.push({ toMillis(come), toMillis(leave) });
    }

    // 첫 사람 입장
    station.push(arrivals.top());
    arrivals.pop();

    int current = 1;
    int maxCount = 1;

    // 모든 사람 처리
    while (!arrivals.empty()) {
        Info person = arrivals.top();
        arrivals.pop();

        // 현재 도착한 사람의 시간보다 먼저 나간 사람들 제거
        while (!station.empty() && station.top().leave <= person.arrive) {
            station.pop();
            current--;
        }

        // 새 사람 입장
        station.push(person);
        current++;

        maxCount = max(maxCount, current);
    }

    cout << maxCount;
    return 0;
}