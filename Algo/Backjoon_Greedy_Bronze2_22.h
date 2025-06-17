#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& x : A) cin >> x;

    int total = 0;
    for (int x : A) total += x;

    vector<bool> dp(total + 1, false);
    dp[0] = true;

    for (int a : A) {
        for (int s = total; s >= a; --s) {
            if (dp[s - a]) dp[s] = true;
        }
    }

    for (int s = total; s >= 0; --s) {
        if (s % 2 == 0 && dp[s]) {
            cout << s / 2 << endl;
            return 0;
        }
    }
    return 0;
}
