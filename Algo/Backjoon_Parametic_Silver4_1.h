#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N, B;
        cin >> N >> B;
        if (N == -1 && B == -1) break;

        vector<int> population(N);
        int maxPop = 0;
        for (int i = 0; i < N; ++i) {
            cin >> population[i];
            maxPop = max(maxPop, population[i]);
        }

        // �̺� Ž��: �� ��ǥ�Դ� �ִ� ��� ���� �̺� Ž��
        int left = 1, right = maxPop;
        int answer = maxPop;

        while (left <= right) {
            int mid = (left + right) / 2;

            long long boxesNeeded = 0;
            for (int i = 0; i < N; ++i) {
                // �ø�(ceil) ȿ��: (�α� + mid - 1) / mid
                boxesNeeded += (population[i] + mid - 1) / mid;
            }

            if (boxesNeeded <= B) {
                answer = mid;
                right = mid - 1; // �� ���� �� �ִ��� Ȯ��
            }
            else {
                left = mid + 1; // mid�δ� �����ϹǷ� ����
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
