#pragma once
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int arr[1001][1001];
int prefix[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i - 1][j - 1];
        }
    }

    int len = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = len; k < min(n - i + 1, m - j + 1); k++) {
                int sum = prefix[i + k][j + k] - prefix[i + k][j - 1] - prefix[i - 1][j + k] + prefix[i - 1][j - 1];

                if (sum == 0) {
                    len = max(len, k + 1);
                }
                else {
                    break;
                }
            }

        }
    }

    cout << len;
}
