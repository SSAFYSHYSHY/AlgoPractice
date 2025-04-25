#pragma once
#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000000000

using namespace std;

bool Calc(long long mid, int n, const vector<int>& v) {
    long long sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += (mid / v[i]);
    }
    return sum >= n;  // ÇÙ½É ¼öÁ¤
}

long long solution(int n, vector<int> times) {
    long long answer = MAX * (long long)n;
    long long l = 1, r = answer;

    while (l <= r) {
        long long mid = (l + r) / 2;

        if (Calc(mid, n, times)) {
            answer = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return answer;
}