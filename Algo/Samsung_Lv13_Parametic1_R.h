#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int q;
vector<long long> v(1);
vector<bool> visited(1, false);

bool Calc(long long mid, int r) {
    long long last = -1e18;
    int cnt = 0;
    for (size_t i = 1; i < v.size(); i++) {
        if (visited[i]) continue;
        if (v[i] - last > mid) {
            cnt++;
            last = v[i];
        }
    }
    return cnt <= r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> q;
    while (q--) {
        int ord;
        cin >> ord;

        if (ord == 100) {
            int n;
            cin >> n;
            v.resize(1); visited.resize(1, false);
            for (int i = 1; i <= n; i++) {
                long long x;
                cin >> x;
                v.push_back(x);
                visited.push_back(false);
            }
        }
        else if (ord == 200) {
            long long x;
            cin >> x;
            v.push_back(x);
            visited.push_back(false);
        }
        else if (ord == 300) {
            int idx;
            cin >> idx;
            visited[idx] = true;
        }
        else if (ord == 400) {
            int r;
            cin >> r;
            vector<long long> v_temp;
            for (size_t i = 1; i < v.size(); i++) {
                if (!visited[i]) v_temp.push_back(v[i]);
            }
            if (v_temp.empty()) {
                cout << 0 << "\n";
                continue;
            }
            if (r == 1) {
                cout << v_temp.back() - v_temp.front() << "\n";
                continue;
            }
            long long l = 0, right = 1e18, ans = 0;
            while (l <= right) {
                long long mid = (l + right) / 2;
                long long last = -1e18;
                int cnt = 0;
                for (auto x : v_temp) {
                    if (x - last > mid) {
                        cnt++;
                        last = x;
                    }
                }
                if (cnt <= r) {
                    ans = mid;
                    right = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            cout << ans << "\n";
        }
    }
}