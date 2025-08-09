#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000001];
int left_max[1000001];
int right_max[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    left_max[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        left_max[i] = max(left_max[i - 1], arr[i]);
    }

    right_max[n] = arr[n];
    for (int i = n - 1; i >= 1; i--) {
        right_max[i] = max(right_max[i + 1], arr[i]);
    }

    int a_cnt = 0, b_cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (left_max[i] > right_max[i + 1]) a_cnt++;
        else if (left_max[i] < right_max[i + 1]) b_cnt++;
    }

    if (a_cnt > b_cnt) cout << "R";
    else if (a_cnt < b_cnt) cout << "B";
    else cout << "X";
}
