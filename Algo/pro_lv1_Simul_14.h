#pragma once
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 123456789;

    int sum = 0;
    for (int i = 0; i < signs.size(); i++) {
        if (!signs[i]) {
            sum -= absolutes[i];
        }
        else {
            sum += absolutes[i];
        }
    }
    answer = sum;

    return answer;
}