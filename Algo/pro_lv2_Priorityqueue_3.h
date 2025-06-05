#pragma once
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int timeToInt(const string& timeStr) {
    int hour = stoi(timeStr.substr(0, 2));
    int min = stoi(timeStr.substr(3, 2));
    return hour * 60 + min;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> times;

    for (const auto& bt : book_time) {
        int start = timeToInt(bt[0]);
        int end = timeToInt(bt[1]) + 10; // 청소 시간 포함
        times.push_back({ start, end });
    }

    // 시작 시간 기준 정렬
    sort(times.begin(), times.end());

    // 종료 시간을 담는 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;

    for (const auto& t : times) {
        int start = t.first, end = t.second;

        if (!pq.empty() && pq.top() <= start) {
            pq.pop(); // 이전 방 재사용 가능
        }
        pq.push(end); // 새로운 예약 추가
    }

    return pq.size(); // 동시에 필요한 방의 수
}