#pragma once
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, k;
vector<double> cables;

bool canCut(double length) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += (int)(cables[i] / length); // 정수 개수만 자를 수 있음
    }
    return cnt >= k;
}

int main() {
    cin >> n >> k;
    cables.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cables[i];
    }

    double l = 0.01, r = 100000.0;
    double ans = 0.0;

    while (r - l > 1e-4) {
        double mid = (l + r) / 2.0;
        if (canCut(mid)) {
            ans = mid;
            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << floor(ans * 100) / 100 << '\n'; // 또는 round(ans * 100) / 100
}
