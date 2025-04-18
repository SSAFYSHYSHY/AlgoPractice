#pragma once
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> s;

    for (int i = progresses.size() - 1; i >= 0; i--) {
        int rest = 100 - progresses[i];
        int days = ceil((double)rest / speeds[i]);
        s.push(days);
    }

    while (!s.empty()) {
        int top, cnt = 1;
        top = s.top();
        s.pop();

        while (!s.empty() && s.top() <= top) {
            cnt++;
            s.pop();
        }

        answer.push_back(cnt);
    }


    return answer;
}