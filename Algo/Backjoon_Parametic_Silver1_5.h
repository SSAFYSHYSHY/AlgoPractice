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
        if (weight <= limit) continue; // �� �� �ִ� ���Դ� ���ġ �����ϹǷ� ����

        // �� �� ���� ���� �� ���� ��ġ �ٲٸ� �� ��
        const vector<int>& where = it->second;
        if (where.size() != 2) return false;
        if (where[0] / n != where[1] / n) return false; // �� �ٸ��� �� ����
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
        positions[row1[i]].push_back(i); // 0��° �� i ��ġ �� 0~n-1
    }

    for (int i = 0; i < n; ++i) {
        cin >> row2[i];
        if (positions.find(row2[i]) == positions.end()) {
            positions[row2[i]] = vector<int>();
        }
        positions[row2[i]].push_back(i + n); // 1��° �� i ��ġ �� n~2n-1
    }

    // �̺� Ž��: �� �� �ִ� �ִ� ���Ը� �ּ�ȭ
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
