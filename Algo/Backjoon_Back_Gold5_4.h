#pragma once
#include <iostream>
#include <set>
#include <string>
using namespace std;

using ll = long long;

ll mypow(int a, int b) {
    if (a == 0) return 0;
    if (a == 1) return 1;
    if (b == 0) return 1;
    return a * mypow(a, b - 1);
}

set<ll> sdsum(const string& str) {
    set<ll> s;
    s.insert(stoll(str));
    for (int i = 1; i < (int)str.length(); i++) {
        set<ll> tmps = sdsum(str.substr(i));
        for (ll j : tmps) {
            s.insert(stoll(str.substr(0, i)) + j);
        }
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        bool flg = false;
        for (char c : s) {
            if (c - '0' >= 2) {
                flg = true;
                break;
            }
        }

        if (!flg) {
            cout << "Hello, BOJ 2023!\n";
            continue;
        }

        set<ll> sums = sdsum(s);
        int cnt = 1;

        for (int i = 2; i < 10; i++) {
            ll m = 0;
            for (char c : s) {
                m += mypow(c - '0', i);
            }
            if (sums.find(m) != sums.end()) cnt++;
        }
        cout << cnt << "\n";
    }
}