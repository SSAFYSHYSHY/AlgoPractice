#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// t분까지 이발한 고객 수 계산
long long servedUntil(const vector<int>& m, long long t) {
    long long total = 0;
    for (int time : m) {
        total += t / time + 1;
    }
    return total;
}

int main() {
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int B;
        long long N;
        cin >> B >> N;

        vector<int> m(B);
        for (int i = 0; i < B; i++) {
            cin >> m[i];
        }

        // 이분 탐색으로 최소 시간 찾기
        long long l = 0, r = 1LL << 50; // 충분히 큰 범위
        long long time = -1;

        while (l <= r) {
            long long mid = (l + r) / 2;
            if (servedUntil(m, mid) >= N) {
                time = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        // time - 1까지 처리된 손님 수
        long long servedBefore = servedUntil(m, time - 1);
        long long toGo = N - servedBefore;

        // time 시점에 비는 이발사 중 N번째 사람을 처리하는 이발사 찾기
        int result = -1;
        for (int i = 0; i < B; i++) {
            if (time % m[i] == 0) {
                toGo--;
                if (toGo == 0) {
                    result = i + 1; // 이발사는 1번부터 시작
                    break;
                }
            }
        }

        cout << "Case #" << caseNum << ": " << result << '\n';
    }

    return 0;
}
