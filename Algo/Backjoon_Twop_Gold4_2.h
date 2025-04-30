#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> belt(n);
    for (int i = 0; i < n; ++i) cin >> belt[i];

    vector<int> kind(d + 1, 0);
    int cnt = 0; // ���� ���� ��

    // �ʱ� ������ ����
    for (int i = 0; i < k; ++i) {
        if (kind[belt[i]]++ == 0) cnt++;
    }

    int ans = cnt + (kind[c] == 0 ? 1 : 0);

    for (int i = 1; i < n; ++i) {
        // �����̵� ������: i ~ i+k-1 (�� k��), mod n
        int remove = belt[(i - 1) % n];
        if (--kind[remove] == 0) cnt--;

        int add = belt[(i + k - 1) % n];
        if (++kind[add] == 1) cnt++;

        ans = max(ans, cnt + (kind[c] == 0 ? 1 : 0));
    }

    cout << ans;
    return 0;
}
