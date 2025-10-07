#pragma once
#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    if (x < n || x > 26 * n) {
        cout << "!";
        return 0;
    }

    int z = 0, remain = 0;
    for (; z <= n; z++) {
        if (n - z > x - 26 * z) {
            remain = x - 26 * (z - 1);
            break;
        }
    }
    z--;

    int a = n - z - 1;
    int mid = remain - a;

    for (int i = 0; i < a; i++) cout << 'A';
    if (z != n) cout << char('A' + mid - 1);
    for (int i = 0; i < z; i++) cout << 'Z';
}