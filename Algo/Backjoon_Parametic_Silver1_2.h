#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>  // for M_PI or acos

using namespace std;

int t;

// �� ��Ȯ�ϰ� ǥ��
const double PI = acos(-1);  // �Ǵ� 3.14159265358979

bool Calc(const vector<int>& v, double mid, int totalPeople) {
    int cnt = 0;
    for (int r : v) {
        cnt += int((PI * r * r) / mid);
    }
    return cnt >= totalPeople;
}

int main() {
    cin >> t;

    cout << fixed;
    cout.precision(4);

    while (t--) {
        int n, f;
        cin >> n >> f;

        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        // �̺� Ž�� ���� ����
        double l = 0.0;
        double r = PI * *max_element(v.begin(), v.end()) * *max_element(v.begin(), v.end());
        double ans = 0.0;

        // ���� ���� ���� �̺� Ž��
        while (r - l > 1e-6) {
            double mid = (l + r) / 2.0;
            if (Calc(v, mid, f + 1)) {
                ans = mid;
                l = mid;
            }
            else {
                r = mid;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
