#pragma once
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> result;
    unordered_set<string> used;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        vector<string> apps(m);
        for (int j = 0; j < m; j++) {
            cin >> apps[j];
        }

        for (int j = 0; j < m; j++) {
            if (used.find(apps[j]) == used.end()) {
                used.insert(apps[j]);
                result.push_back(apps[j]);
                break;
            }
        }
    }

    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i];
        if (i + 1 < result.size()) cout << " ";
    }

    return 0;
}