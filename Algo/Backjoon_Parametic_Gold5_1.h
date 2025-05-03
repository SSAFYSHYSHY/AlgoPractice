#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100001

int N, L;
int countByCitation[MAX_N];

bool possible(int h) {
    int need = 0;

    // h �̻� �ο�� �� ��
    int high = countByCitation[h];

    // ������ ���� L�� ä�� �� �ִ°�?
    if (high >= h) return true;
    need = h - high;

    return need <= L;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    fill(countByCitation, countByCitation + MAX_N, 0);

    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        countByCitation[c]++;
    }

    // ������: countByCitation[i] = i �̻� �ο�� �� ��
    for (int i = MAX_N - 2; i >= 0; i--) {
        countByCitation[i] += countByCitation[i + 1];
    }

    int l = 0, r = N, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (possible(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
