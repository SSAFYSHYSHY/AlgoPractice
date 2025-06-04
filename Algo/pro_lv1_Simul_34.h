#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    string s;

    while (n > 0) {
        s += to_string(n % 3);
        n /= 3;
    }

    int pow = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        answer += (s[i] - '0') * pow;
        pow *= 3;
    }

    return answer;
}