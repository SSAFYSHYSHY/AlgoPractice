#pragma once
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 1234567890;

    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += (a[i] * b[i]);
    }

    answer = sum;

    return answer;
}