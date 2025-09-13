#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<string, int> cnt;
    long long total = 0;  // ���ݱ��� ��ü ���� ����
    int warnings = 0;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;

        int before = cnt[name];
        long long others = total - before;

        if (before > others) {
            warnings++;
        }

        cnt[name]++;
        total++;
    }

    cout << warnings << "\n";
    return 0;
}