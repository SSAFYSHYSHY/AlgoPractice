#pragma once
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int len = numbers.size();
    vector<int> answer(len, -1);
    stack<int> s;

    for (int i = len - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= numbers[i]) {
            s.pop();
        }

        if (!s.empty()) {
            answer[i] = s.top();
        }

        s.push(numbers[i]);
    }

    return answer;
}