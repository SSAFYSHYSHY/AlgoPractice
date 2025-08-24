#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        for (int j = 0; j < t; j++) {
            string tag;
            cin >> tag;
            mp[tag]++;
        }
    }

    // 1. �ִ� �� ���ϱ�
    int max_cnt = 0;
    for (auto& p : mp) {
        if (p.second > max_cnt) max_cnt = p.second;
    }

    // 2. �ֺ��� �� ������ Ȯ��
    int count_max = 0;
    string ans;
    for (auto& p : mp) {
        if (p.second == max_cnt) {
            count_max++;
            ans = p.first;
        }
    }

    // 3. ���
    if (count_max == 1) cout << ans;
    else cout << -1;
}
