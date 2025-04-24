#pragma once
#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> s;

int solution(vector<int> order) {
    int answer = 0;
    int curr = 1;
    int idx = 0;

    while (curr <= order.size()) {
        if (order[idx] == curr) {
            answer++;
            idx++;
            curr++;
        }
        else if (!s.empty() && s.top() == order[idx]) {
            s.pop();
            answer++;
            idx++;
        }
        else {
            s.push(curr);
            curr++;
        }
    }

    while (!s.empty() && s.top() == order[idx]) {
        s.pop();
        answer++;
        idx++;
    }

    return answer;
}