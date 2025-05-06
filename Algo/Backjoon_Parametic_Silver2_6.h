#pragma once
#include <iostream>
#include <algorithm>
#define MAX 100000000000LL

using namespace std;

long long n, k, ans = 0;
long long arr[100001];

bool Calc(long long mid) {
    long long cnt = 1;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) return false;

        if (sum + arr[i] > mid) {
            cnt++;
            sum = 0;
        }

        sum += arr[i];
    }

    return cnt <= k;
}

int main() {
    cin >> n >> k;

    long long l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        r += arr[i];
    }

    long long ans = r;

    while (l <= r) {
        long long mid = (l + r) / 2;

        if (Calc(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;
}
