#pragma once
#include <iostream>

using namespace std;

int main() {

    long long n, ans = 0, a = 0;

    cin >> n;

    while (a < n) {
        if (a == 0)
            a++;
        else
            a *= 2;
        ans++;
    }

    cout << ans;
}