#pragma once
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {

    string s = to_string(x);
    int sum = 0;

    for (int i = 0; i < s.length(); i++) {
        sum += (int)(s[i] - '0');
    }

    if (x % sum == 0) {
        return true;
    }
    else {
        return false;
    }
}