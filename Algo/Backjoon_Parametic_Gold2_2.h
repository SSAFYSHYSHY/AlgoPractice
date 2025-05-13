#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력으로 주어질 변수들: n은 원소 수, m은 그룹 수
int n, m;

// arr: 원래 주어진 숫자 배열
// answerGroupSizes: 가능한 그룹 분할을 저장
vector<int> arr;
vector<int> answerGroupSizes;

// 특정 mid 값(그룹 최대 합의 상한선)으로 그룹을 나누었을 때
// 그룹 개수가 m 이하로 가능한지를 확인하는 함수
bool isPossible(int mid) {
    vector<int> tempGroupSizes; // 현재 mid에서 나눠진 그룹의 크기들을 저장
    int cnt = 1;                // 그룹 개수. 시작은 1개부터.
    int sum = 0;                // 현재 그룹의 누적 합
    int groupSize = 0;          // 현재 그룹에 포함된 원소 수

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) return false; // 어떤 하나의 원소가 mid보다 크면 그룹 불가능

        // 누적합이 mid를 초과하면 그룹을 새로 나눈다
        if (sum + arr[i] > mid) {
            tempGroupSizes.push_back(groupSize); // 지금까지 만든 그룹 크기 저장
            cnt++;                                // 그룹 개수 증가
            sum = arr[i];                         // 새 그룹 시작
            groupSize = 1;
        }
        else {
            sum += arr[i];   // 현재 그룹에 계속 더함
            groupSize++;
        }
    }

    // 마지막 그룹 처리
    tempGroupSizes.push_back(groupSize);

    // 그룹 개수가 m 이하일 경우 현재 그룹 구성을 정답 후보로 저장
    if (cnt <= m) {
        answerGroupSizes = tempGroupSizes;
        return true;
    }

    return false; // m개를 넘으면 불가능
}

int main() {
    // 입력 받기
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 이분 탐색을 위한 시작점과 끝점 설정
    int l = *max_element(arr.begin(), arr.end()); // 최소값은 가장 큰 원소 이상이어야 함
    int r = 300000;
    int answer = 0;

    // 이분 탐색 시작
    while (l <= r) {
        int mid = (l + r) / 2;

        // 현재 mid로 그룹이 가능하면 더 작은 mid를 시도
        if (isPossible(mid)) {
            answer = mid;   // 가능한 경우로 정답 후보 저장
            r = mid - 1;    // 더 작은 mid 시도
        }
        else {
            l = mid + 1;    // 불가능하므로 더 큰 mid 시도
        }
    }

    // 최소 가능한 최대 그룹 합 출력
    cout << answer << "\n";

    // m개의 그룹이 되도록 그룹 수 보정
    // 현재 answerGroupSizes는 m보다 작을 수도 있으므로 1로 쪼개서 보정
    int remainingGroups = m - answerGroupSizes.size();
    vector<int> finalGroups;

    for (int i = 0; i < answerGroupSizes.size(); i++) {
        // 그룹의 크기가 1보다 크고, 남은 그룹 수가 있을 때 1로 쪼갠다
        while (answerGroupSizes[i] > 1 && remainingGroups > 0) {
            finalGroups.push_back(1);
            answerGroupSizes[i]--;
            remainingGroups--;
        }
        finalGroups.push_back(answerGroupSizes[i]); // 나머지는 그대로 넣음
    }

    // 최종 그룹 크기 출력
    for (int i = 0; i < finalGroups.size(); i++) {
        cout << finalGroups[i] << " ";
    }
    cout << "\n";

    return 0;
}
