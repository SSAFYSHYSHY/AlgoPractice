#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long n, m, x, y;
long long arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    while (m--) {
        cin >> x >> y;

        // [x, y] 범위에 있는 원소의 개수 = upper_bound - lower_bound
        long long left = lower_bound(arr, arr + n, x) - arr;
        long long right = upper_bound(arr, arr + n, y) - arr;

        cout << right - left << "\n";
    }

    return 0;
}
