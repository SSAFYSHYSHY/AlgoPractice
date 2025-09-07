#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <sstream>

using namespace std;

string Calc(const set<int>& s) {
    string res;
    for (int x : s) {
        res += to_string(x) + ",";
    }
    return res;
}

int main() {
    int T, P;
    cin >> T >> P;

    vector<set<int>> v(P + 1);

    int i, j;
    while (cin >> i >> j) {
        v[i].insert(j);
    }

    unordered_set<string> map;

    for (int p = 1; p <= P; p++) {
        string key = Calc(v[p]);
        map.insert(key);
    }

    cout << map.size() << "\n";
}
