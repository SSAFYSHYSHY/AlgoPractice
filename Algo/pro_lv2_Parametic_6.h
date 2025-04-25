#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �־��� �Ÿ��� ������ n�� ���Ϸ� ������ �� �ִ°�?
bool canRemoveWithMinDistance(const vector<int>& rocks, int distance, int n, int mid) {
    int removed = 0;
    int prev = 0;

    for (int i = 0; i < rocks.size(); i++) {
        if (rocks[i] - prev < mid) {
            removed++; // ���� ������ �����ؾ� �ּ� �Ÿ��� ���� ����
        }
        else {
            prev = rocks[i]; // �� ������ ����
        }
    }

    // ������ ���� üũ
    if (distance - prev < mid) removed++;

    return removed <= n;
}

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end()); // ���� ����
    int left = 1;
    int right = distance;
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canRemoveWithMinDistance(rocks, distance, n, mid)) {
            answer = mid;        // ���� mid�� ������ ��, �� ū ���� �������� Ȯ��
            left = mid + 1;
        }
        else {
            right = mid - 1;     // mid�� �Ұ���, �� ���� �� Ž��
        }
    }

    return answer;
}

int main() {
    int distance = 25;
    vector<int> rocks = { 2, 14, 11, 21, 17 };
    int n = 2;

    cout << solution(distance, rocks, n) << "\n"; // ���: 4

    return 0;
}