#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

int n;
vector<int> row1, row2;
map<int, vector<int> > positions;

bool can(int limit) {
    for (map<int, vector<int> >::iterator it = positions.begin(); it != positions.end(); ++it) {
        int weight = it->first;
        if (weight <= limit) continue; // 들 수 있는 무게는 재배치 가능하므로 무시

        // 들 수 없는 무게 → 절대 위치 바꾸면 안 됨
        const vector<int>& where = it->second;
        if (where.size() != 2) return false;
        if (where[0] / n != where[1] / n) return false; // 줄 다르면 못 붙임
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    row1.resize(n);
    row2.resize(n);
    positions.clear();

    for (int i = 0; i < n; ++i) {
        cin >> row1[i];
        if (positions.find(row1[i]) == positions.end()) {
            positions[row1[i]] = vector<int>();
        }
        positions[row1[i]].push_back(i); // 0번째 줄 i 위치 → 0~n-1
    }

    for (int i = 0; i < n; ++i) {
        cin >> row2[i];
        if (positions.find(row2[i]) == positions.end()) {
            positions[row2[i]] = vector<int>();
        }
        positions[row2[i]].push_back(i + n); // 1번째 줄 i 위치 → n~2n-1
    }

    // 이분 탐색: 들 수 있는 최대 무게를 최소화
    int l = 0, r = 1e9;
    int answer = 1e9;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (can(mid)) {
            answer = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << answer << "\n";
    return 0;
}
