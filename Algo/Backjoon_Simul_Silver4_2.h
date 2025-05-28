#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, ans = 0;
char arr[51][51];

void Calc() {
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == arr[i][j + 1]) {
                cnt++;
            }
            else {
                if (ans < cnt) ans = cnt;
                cnt = 1;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i][j] == arr[i + 1][j]) {
                cnt++;
            }
            else {
                if (ans < cnt) ans = cnt;
                cnt = 1;
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            swap(arr[i][j], arr[i][j + 1]);
            Calc();
            swap(arr[i][j], arr[i][j + 1]);
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            swap(arr[i][j], arr[i + 1][j]);
            Calc();
            swap(arr[i][j], arr[i + 1][j]);
        }
    }

    cout << ans << '\n';

    return 0;
}
