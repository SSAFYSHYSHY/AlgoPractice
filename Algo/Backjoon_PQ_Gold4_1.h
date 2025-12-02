#pragma once
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        priority_queue<int> maxpq;
        priority_queue<int, vector<int>, greater<int>> minpq;
        map<int, int> cnt;

        auto clean = [&]() {
            while (!maxpq.empty() && cnt[maxpq.top()] == 0)
                maxpq.pop();
            while (!minpq.empty() && cnt[minpq.top()] == 0)
                minpq.pop();
            };

        while (k--) {
            char cmd;
            int n;
            cin >> cmd >> n;

            if (cmd == 'I') {
                maxpq.push(n);
                minpq.push(n);
                cnt[n]++;
            }
            else {
                clean();

                if (n == 1) {
                    if (!maxpq.empty()) {
                        cnt[maxpq.top()]--;
                        maxpq.pop();
                    }
                }
                else {
                    if (!minpq.empty()) {
                        cnt[minpq.top()]--;
                        minpq.pop();
                    }
                }
            }
            clean();
        }

        clean();
        if (maxpq.empty() || minpq.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << maxpq.top() << " " << minpq.top() << "\n";
        }
    }

    return 0;
}