#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int dIdx = n - 1, pIdx = n - 1;

    // �ڿ������� ���� (���� �� �� ���� ó��)
    while (dIdx >= 0 || pIdx >= 0) {
        // ���� ���� ���� �� ��� ��ġ ã��
        while (dIdx >= 0 && deliveries[dIdx] == 0) dIdx--;
        // ���� ���� ���� �� ���� ��ġ ã��
        while (pIdx >= 0 && pickups[pIdx] == 0) pIdx--;

        if (dIdx < 0 && pIdx < 0) break; // �� �������� ����

        int farthest = max(dIdx, pIdx) + 1; // 1-based �Ÿ�
        answer += (long long)farthest * 2;

        int capLeft = cap;
        // ��� ó��
        while (dIdx >= 0 && capLeft > 0) {
            if (deliveries[dIdx] <= capLeft) {
                capLeft -= deliveries[dIdx];
                deliveries[dIdx] = 0;
                dIdx--;
            }
            else {
                deliveries[dIdx] -= capLeft;
                capLeft = 0;
            }
        }

        capLeft = cap;
        // ���� ó��
        while (pIdx >= 0 && capLeft > 0) {
            if (pickups[pIdx] <= capLeft) {
                capLeft -= pickups[pIdx];
                pickups[pIdx] = 0;
                pIdx--;
            }
            else {
                pickups[pIdx] -= capLeft;
                capLeft = 0;
            }
        }
    }
    return answer;
}
