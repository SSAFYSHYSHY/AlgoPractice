#pragma once
#include <iostream>
#include <cstring>
using namespace std;

int arr[6][3];
bool flag;

bool all_zero() {
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++)
            if (arr[i][j]) return false;
    return true;
}

void dfs(int a, int b, int cnt) {
    if (a == 5 && cnt == 15) {
        if (all_zero()) flag = true;
        return;
    }
    if (arr[a][0] && arr[b][2]) {
        arr[a][0]--; arr[b][2]--;
        dfs(a, b + 1, cnt + 1);
        arr[a][0]++; arr[b][2]++;
    }
    if (arr[a][1] && arr[b][1]) {
        arr[a][1]--; arr[b][1]--;
        dfs(a, b + 1, cnt + 1);
        arr[a][1]++; arr[b][1]++;
    }
    if (arr[a][2] && arr[b][0]) {
        arr[a][2]--; arr[b][0]--;
        dfs(a, b + 1, cnt + 1);
        arr[a][2]++; arr[b][0]++;
    }
    if (b == 6) dfs(a + 1, a + 2, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 0; t < 4; t++) {
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
                cin >> arr[i][j];
        flag = false;
        dfs(0, 1, 0);
        cout << flag << ' ';
    }
}
