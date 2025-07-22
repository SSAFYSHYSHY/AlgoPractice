#pragma once
#include <iostream>

using namespace std;

int n, arr[11];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        bool flag = true;

        for (int j = 1; j <= 10; j++) {
            cin >> arr[j];
            if (arr[j] != (j - 1) % 5 + 1)
                flag = false;
        }

        if (flag == true)
            cout << i << '\n';
    }
}