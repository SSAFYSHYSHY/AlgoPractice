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

    // h 이상 인용된 논문 수
    int high = countByCitation[h];

    // 부족한 수를 L로 채울 수 있는가?
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

    // 누적합: countByCitation[i] = i 이상 인용된 논문 수
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
