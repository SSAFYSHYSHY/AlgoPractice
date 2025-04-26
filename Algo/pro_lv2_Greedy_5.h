#pragma once
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // ����
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // ���� �������� ������ �ִ� ��� ����
    vector<int> realLost;
    vector<int> realReserve;

    for (int l : lost) {
        if (find(reserve.begin(), reserve.end(), l) != reserve.end()) {
            reserve.erase(find(reserve.begin(), reserve.end(), l));
        }
        else {
            realLost.push_back(l);
        }
    }

    for (int r : reserve) {
        if (find(lost.begin(), lost.end(), r) == lost.end()) {
            realReserve.push_back(r);
        }
    }

    // �����ֱ�
    for (int r : realReserve) {
        auto it = find(realLost.begin(), realLost.end(), r - 1);
        if (it != realLost.end()) {
            realLost.erase(it);
            continue;
        }

        it = find(realLost.begin(), realLost.end(), r + 1);
        if (it != realLost.end()) {
            realLost.erase(it);
        }
    }

    // ���� ������ �л� �� = ��ü - ü���� �� ���� �л� ��
    return n - realLost.size();
}