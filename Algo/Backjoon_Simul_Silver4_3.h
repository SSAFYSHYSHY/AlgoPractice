#pragma once
#include <iostream>
#include <algorithm>

#define MAXN 1000001

using namespace std;

bool arr[MAXN];

void Calc() {
    fill(arr, arr + MAXN, true);
    arr[0] = arr[1] = false;

    for (int i = 2; i * i < MAXN; i++) {
        if (arr[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                arr[j] = false;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    Calc();

    while (t--) {
        int ans = 0;
        int n;
        cin >> n;

        for (int i = 2; i <= n / 2; i++) {
            int a = i;
            int b = n - i;

            if (arr[a] && arr[b]) {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
