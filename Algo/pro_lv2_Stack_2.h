#pragma once
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1, cnt = 1;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); i++) {
        q.push({ i, priorities[i] });
        pq.push(priorities[i]);
    }

    while (1) {
        pair<int, int> p = q.front();
        q.pop();

        if (p.second != pq.top()) {
            q.push(p);
        }
        else {
            if (p.first == location) {
                answer = cnt;
                break;
            }
            else {
                cnt++;
                pq.pop();
            }
        }

    }

    return answer;
}