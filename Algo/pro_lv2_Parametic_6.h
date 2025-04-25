#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 주어진 거리로 바위를 n개 이하로 제거할 수 있는가?
bool canRemoveWithMinDistance(const vector<int>& rocks, int distance, int n, int mid) {
    int removed = 0;
    int prev = 0;

    for (int i = 0; i < rocks.size(); i++) {
        if (rocks[i] - prev < mid) {
            removed++; // 현재 바위를 제거해야 최소 거리를 유지 가능
        }
        else {
            prev = rocks[i]; // 이 바위는 유지
        }
    }

    // 마지막 구간 체크
    if (distance - prev < mid) removed++;

    return removed <= n;
}

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end()); // 바위 정렬
    int left = 1;
    int right = distance;
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canRemoveWithMinDistance(rocks, distance, n, mid)) {
            answer = mid;        // 현재 mid는 가능한 값, 더 큰 값도 가능할지 확인
            left = mid + 1;
        }
        else {
            right = mid - 1;     // mid는 불가능, 더 작은 값 탐색
        }
    }

    return answer;
}

int main() {
    int distance = 25;
    vector<int> rocks = { 2, 14, 11, 21, 17 };
    int n = 2;

    cout << solution(distance, rocks, n) << "\n"; // 결과: 4

    return 0;
}