#pragma once
#include <string>
#include <vector>

using namespace std;

bool Calc(int num) {
    int cnt = 0;

    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            cnt++;
        }
    }

    if (cnt % 2 == 0) {
        return true;
    }
    return false;
}

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        if (Calc(i)) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }

    return answer;
}