#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> c(n);

    double sum = 0.0, ans;

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        sum += c[i] * c[i] * c[i];
    }

    ans = cbrt(sum);
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}