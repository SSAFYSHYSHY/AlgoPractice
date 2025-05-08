#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

long long arr[10001];
long long prefix[10001];
bool visited[100000001];

void Prime() {
    memset(visited, true, sizeof(visited));
    visited[0] = visited[1] = false;

    for (int i = 2; i * i <= 1000000; i++) {
        if (visited[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                visited[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Prime();

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // 배열 초기화는 안 해도 되지만 안전하게 해주는 것이 좋음
        memset(arr, 0, sizeof(long long) * (n + 1));
        memset(prefix, 0, sizeof(long long) * (n + 2));

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        prefix[0] = 0;
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        bool found = false;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                long long sum = prefix[i + len] - prefix[i];
                if (visited[sum]) {
                    cout << "Shortest primed subsequence is length " << len << ": ";
                    for (int j = i; j < i + len; ++j) {
                        cout << arr[j] << " ";
                    }
                    cout << "\n";
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) {
            cout << "This sequence is anti-primed.\n";
        }
    }

    return 0;
}
