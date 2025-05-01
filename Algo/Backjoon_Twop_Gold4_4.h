#pragma once
#include <iostream>
#include <vector>

using namespace std;

int t;
int n, m, k;
vector<int> v;

int main() {
    cin >> t;

    while (t--) {
        int ans = 0;
        v.clear();

        cin >> n >> m >> k;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            v.push_back(num);
        }

        // ���� ó��: n == m�̸� ��ü �迭�� 2�� ���� �� �ȵ� (�ߺ�)
        if (n != m) {
            for (int i = 0; i < m - 1; i++) {
                v.push_back(v[i]);
            }
        }

        int sum = 0, l = 0;
        for (int r = 0; r < v.size(); r++) {
            sum += v[r];

            // ������ ũ�⸦ m���� ����
            if (r - l + 1 > m) {
                sum -= v[l];
                l++;
            }

            if (r - l + 1 == m && sum < k) {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
