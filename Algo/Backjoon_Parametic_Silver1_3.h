#pragma once
#include <iostream>
#include <cmath>
using namespace std;

double a, b, c, d, m, t;

bool canReach(double v) {
    double fuelPerHour = a * pow(v, 4) + b * pow(v, 3) + c * pow(v, 2) + d * v;
    double time = m / v;
    double totalFuel = fuelPerHour * time;
    return totalFuel <= t;
}

int main() {
    cout << fixed;
    cout.precision(2);

    while (cin >> a >> b >> c >> d >> m >> t) {
        double l = 0.0, r = 1000.0;
        double ans = 0.0;

        for (int i = 0; i < 100; i++) {
            double mid = (l + r) / 2.0;
            if (canReach(mid)) {
                ans = mid;
                l = mid;
            }
            else {
                r = mid;
            }
        }

        ans = floor(ans * 100.0) / 100.0;
        cout << ans << "\n";
    }

    return 0;
}
