#pragma once
#include <iostream>
#include <string>
#include <cmath> 

using namespace std;

int main() {
    int n;
    string s, tar;
    cin >> n;
    cin >> s >> tar;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int diff = abs(s[i] - tar[i]);
        sum += min(diff, 26 - diff);
    }

    cout << sum << '\n';
    return 0;
}
