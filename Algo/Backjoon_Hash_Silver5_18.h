#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 각 시간대별 근무 시간
    int duty[4] = { 4, 6, 4, 10 };
    unordered_map<string, int> work;

    string name;
    for (int week = 0; week < N; week++) {
        for (int shift = 0; shift < 4; shift++) {
            for (int day = 0; day < 7; day++) {
                cin >> name;
                if (name != "-") {
                    work[name] += duty[shift];
                }
            }
        }
    }

    if (work.empty()) {
        cout << "Yes\n";
        return 0;
    }

    int minTime = 1e9, maxTime = -1e9;
    for (auto& p : work) {
        minTime = min(minTime, p.second);
        maxTime = max(maxTime, p.second);
    }

    if (maxTime - minTime <= 12) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
