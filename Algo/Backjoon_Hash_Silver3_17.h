#pragma once
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    map<string, int> pending;
    set<string> solved;
    int solvedProblems = 0;

    for (int i = 0; i < N; ++i) {
        string tmp, id;
        int level;
        cin >> tmp >> id >> level >> tmp >> tmp >> tmp >> tmp;

        if (id == "megalusion") continue;
        if (solved.count(id)) continue;

        if (level == 4) {
            solved.insert(id);
            solvedProblems += pending[id];
        }
        else {
            ++pending[id];
        }
    }

    int total = solvedProblems + solved.size();
    cout.precision(10);
    cout << fixed << (total == 0 ? 0.0 : (100.0 * solved.size() / total));

    return 0;
}
