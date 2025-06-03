#pragma once
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = sqrt(n);

    if (answer * answer == n) {
        return (answer + 1) * (answer + 1);
    }
    else {
        return -1;
    }
}