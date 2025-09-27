#pragma once
#include <iostream>
using namespace std;
int n;
int num[11];

void function(int cnt, int next) {
    if (cnt == n) {
        for (int i = 0; i < n; i++) {
            cout << num[i] << " ";
        }
        cout << '\n';
    }
    else {
        for (int i = 1; i <= n; i++) {
            bool can = true;
            num[cnt] = i;
            for (int j = 0; j < cnt; j++) {
                if (num[j] == num[cnt]) {
                    can = false;
                }
            }
            if (can) {
                if (num[cnt - 1] < num[cnt] && num[cnt] < next) {
                    break;
                }
            }
            if (can) {
                if (next <= num[cnt]) {
                    function(cnt + 1, num[cnt] + 1);
                }
                else {
                    function(cnt + 1, next);
                }
            }
        }
    }
}

int main() {
    cin >> n;
    function(0, 0);
    return 0;
}
