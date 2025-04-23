#pragma once
#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    int cnt = 0;

    while (pq.size() > 1 && pq.top() < K) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        int newnum = first + (second * 2);
        pq.push(newnum);
        cnt++;
    }

    if (!pq.empty() && pq.top() >= K) {
        return cnt;
    }
    else {
        return -1;
    }
}