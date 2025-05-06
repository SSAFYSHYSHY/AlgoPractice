#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long w, h, n;

// 현재 정사각형 한 변의 길이로 n개의 w*h 직사각형을 담을 수 있는지 확인
bool canFit(long long side) {
    return (side / w) * (side / h) >= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> h >> n;

    long long left = 1;
    long long right = 1LL * max(w, h) * n;
    long long ans = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (canFit(mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
