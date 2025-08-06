#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int arr[2000][2000];
int ans = -1;

int main() {
    int n, m, a;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> a;

    int sum = 0;

    for (int j = 0; j < a; j++) {
        for (int i = 0; i < n; i++) {
            sum += arr[i][j];
        }
    }

    ans = max(ans, sum);

    for (int j = a; j < m; j++) {
        for (int i = 0; i < n; i++) {
            sum = sum - arr[i][j - a] + arr[i][j];
        }
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}
