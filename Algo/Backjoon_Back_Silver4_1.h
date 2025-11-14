#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int X, Y;
int a[5];
bool ok;

void backtrack(int idx, long long sum) {
    if (ok) return;

    if (idx == 5) {
        if (sum >= X && sum <= Y) ok = true;
        return;
    }

    //현재 팩을 선택하는 경우
    backtrack(idx + 1, sum + a[idx]);

    //현재 팩을 선택하지 않는 경우
    backtrack(idx + 1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> X >> Y;
        for (int i = 0; i < 5; i++)
            cin >> a[i];

        ok = false;
        backtrack(0, 0);

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
