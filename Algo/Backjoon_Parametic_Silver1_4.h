#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// t�б��� �̹��� �� �� ���
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

        // �̺� Ž������ �ּ� �ð� ã��
        long long l = 0, r = 1LL << 50; // ����� ū ����
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

        // time - 1���� ó���� �մ� ��
        long long servedBefore = servedUntil(m, time - 1);
        long long toGo = N - servedBefore;

        // time ������ ��� �̹߻� �� N��° ����� ó���ϴ� �̹߻� ã��
        int result = -1;
        for (int i = 0; i < B; i++) {
            if (time % m[i] == 0) {
                toGo--;
                if (toGo == 0) {
                    result = i + 1; // �̹߻�� 1������ ����
                    break;
                }
            }
        }

        cout << "Case #" << caseNum << ": " << result << '\n';
    }

    return 0;
}
