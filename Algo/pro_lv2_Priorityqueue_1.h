#pragma once
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<long long> pq;
    long long answer = 0;

    for (long long i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }

    while (n-- && !pq.empty()) {
        int top = pq.top();
        pq.pop();

        if (top > 0) {
            pq.push(top - 1);
        }
    }

    while (!pq.empty()) {
        long long num = pq.top();
        pq.pop();

        answer += num * num;
    }

    return answer;
}