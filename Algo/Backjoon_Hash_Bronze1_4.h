#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> work;
    int shiftTime[4] = { 4, 6, 4, 10 };

    string name;
    for (int i = 0; i < N; i++) {
        for (int shift = 0; shift < 4; shift++) {
            for (int day = 0; day < 7; day++) {
                cin >> name;
                if (name == "-") continue;
                work[name] += shiftTime[shift];
            }
        }
    }

    int minTime = 1e9, maxTime = 0;
    for (auto& p : work) {
        minTime = min(minTime, p.second);
        maxTime = max(maxTime, p.second);
    }

    if (work.empty() || maxTime - minTime <= 12)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}