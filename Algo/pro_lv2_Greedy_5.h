#pragma once
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 정렬
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 도난 당했지만 여벌이 있는 경우 제거
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

    // 빌려주기
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

    // 수업 가능한 학생 수 = 전체 - 체육복 못 빌린 학생 수
    return n - realLost.size();
}