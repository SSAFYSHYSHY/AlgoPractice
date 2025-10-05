#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int dIdx = n - 1, pIdx = n - 1;

    // 뒤에서부터 시작 (가장 먼 집 먼저 처리)
    while (dIdx >= 0 || pIdx >= 0) {
        // 아직 남은 가장 먼 배달 위치 찾기
        while (dIdx >= 0 && deliveries[dIdx] == 0) dIdx--;
        // 아직 남은 가장 먼 수거 위치 찾기
        while (pIdx >= 0 && pickups[pIdx] == 0) pIdx--;

        if (dIdx < 0 && pIdx < 0) break; // 다 끝났으면 종료

        int farthest = max(dIdx, pIdx) + 1; // 1-based 거리
        answer += (long long)farthest * 2;

        int capLeft = cap;
        // 배달 처리
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
        // 수거 처리
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
