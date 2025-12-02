#pragma once
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int t;

int main() {
    cin >> t;

    while (t--) {
        int k;
        long long ans = 0;

        cin >> k;
        priority_queue<long long, vector<long long>, greater<long long> > q;

        for (int i = 0; i < k; i++) {
            int a;
            cin >> a;
            q.push(a);
        }

        while (q.size() > 1) {
            long long sum = q.top();
            q.pop();

            sum += q.top();
            q.pop();

            ans += sum;
            q.push(sum);
        }
        cout << ans << "\n";
    }
    return 0;
}