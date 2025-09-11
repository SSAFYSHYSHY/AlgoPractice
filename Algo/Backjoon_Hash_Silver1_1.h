#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_set<double> quad1, quad2, quad3, quad4;
    unordered_set<string> axis;

    for (int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;

        if (x > 0 && y > 0) quad1.insert((double)y / x);
        else if (x < 0 && y > 0) quad2.insert((double)y / x);
        else if (x < 0 && y < 0) quad3.insert((double)y / x);
        else if (x > 0 && y < 0) quad4.insert((double)y / x);
        else if (x == 0 && y > 0) axis.insert("y");
        else if (x == 0 && y < 0) axis.insert("-y");
        else if (y == 0 && x > 0) axis.insert("x");
        else if (y == 0 && x < 0) axis.insert("-x");
    }

    int res = quad1.size() + quad2.size() + quad3.size() + quad4.size() + axis.size();
    cout << res << "\n";

    return 0;
}