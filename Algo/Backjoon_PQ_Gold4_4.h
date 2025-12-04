#pragma once
#include <iostream>
#include <queue>

using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < n; i++) {
            long long num;
            cin >> num;
            pq.push(num);
        }

        long long score = 1;

        while (pq.size() >= 2) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();

            score = (score * ((a % MOD) * (b % MOD) % MOD)) % MOD;

            pq.push(a * b);
        }

        cout << score << "\n";
    }

    return 0;
}