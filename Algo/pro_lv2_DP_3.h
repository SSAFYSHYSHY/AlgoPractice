#pragma once
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#define MOD 1000000007

using namespace std;

int dp[101][101];

int dx[] = { 1,0 };
int dy[] = { 0,1 };

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (auto& p : puddles) {
        dp[p[1]][p[0]] = -1;
    }

    dp[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            if (dp[i - 1][j] > 0) dp[i][j] += dp[i - 1][j] % MOD;
            if (dp[i][j - 1] > 0) dp[i][j] += dp[i][j - 1] % MOD;
            dp[i][j] %= MOD;
        }
    }

    return dp[n][m];

}