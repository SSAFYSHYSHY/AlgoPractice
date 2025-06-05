#pragma once
#include <string>
#include <vector>

using namespace std;

bool Calc(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        if (Calc(i)) {
            answer++;
        }
    }

    return answer;
}