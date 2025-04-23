#pragma once
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if (s < n) return { -1 };

    vector<int> answer(n, s / n);
    int remain = s % n;

    for (int i = n - 1; i >= 0 && remain > 0; i--) {
        answer[i]++;
        remain--;
    }

    return answer;
}