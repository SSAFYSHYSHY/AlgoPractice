#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[300005];

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int cut = round(n * 0.15);

    int sum = 0, cnt = 0;
    for (int i = cut; i < n - cut; i++) {
        sum += arr[i];
        cnt++;
    }

    int ans = round((double)sum / cnt);
    cout << ans;
}