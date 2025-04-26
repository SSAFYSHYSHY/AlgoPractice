#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cmath>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;

    vector<set<int>> dp(9);  // dp[1] ~ dp[8]

    for (int i = 1; i <= 8; i++) {
        // N을 i번 붙인 수 예: 5, 55, 555 ...
        int repeatedN = 0;
        for (int j = 0; j < i; j++) {
            repeatedN = repeatedN * 10 + N;
        }
        dp[i].insert(repeatedN);

        for (int j = 1; j < i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }

        if (dp[i].count(number)) return i;
    }

    return -1;
}