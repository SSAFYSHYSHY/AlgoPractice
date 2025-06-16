#pragma once
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(x);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < x; ++i) cin >> b[i];

    int i = 0; // 현재 a 배열 위치
    long long answer = 0;
    for (int j = 0; j < x; ++j) {
        long long sum = 0;
        bool found = false;
        while (i < n) {
            sum += a[i++];
            if (sum >= b[j]) {
                answer += (sum - b[j]);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << -1 << endl;
            return 0;
        }
    }

    if (i > n) {
        cout << -1 << endl;
    }
    else {
        cout << answer << endl;
    }

    return 0;
}
