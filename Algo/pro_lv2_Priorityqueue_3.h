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
        int end = timeToInt(bt[1]) + 10; // û�� �ð� ����
        times.push_back({ start, end });
    }

    // ���� �ð� ���� ����
    sort(times.begin(), times.end());

    // ���� �ð��� ��� �ּ� ��
    priority_queue<int, vector<int>, greater<int>> pq;

    for (const auto& t : times) {
        int start = t.first, end = t.second;

        if (!pq.empty() && pq.top() <= start) {
            pq.pop(); // ���� �� ���� ����
        }
        pq.push(end); // ���ο� ���� �߰�
    }

    return pq.size(); // ���ÿ� �ʿ��� ���� ��
}