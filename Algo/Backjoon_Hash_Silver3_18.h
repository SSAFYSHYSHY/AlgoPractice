#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int countPoints(const vector<string>& plist, const unordered_map<string, int>& gCount) {
    int cnt = 0;
    for (const auto& val : plist) {
        auto it = gCount.find(val);
        if (it != gCount.end()) cnt += it->second;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, p;
    cin >> a >> b >> p;

    vector<string> a_p(a), b_p(b), g_p(p);
    for (int i = 0; i < a; i++) cin >> a_p[i];
    for (int i = 0; i < b; i++) cin >> b_p[i];
    for (int i = 0; i < p; i++) cin >> g_p[i];

    // g_p 빈도수 카운트
    unordered_map<string, int> gCount;
    for (const auto& val : g_p) gCount[val]++;

    int a_count = countPoints(a_p, gCount);
    int b_count = countPoints(b_p, gCount);

    if (a_count == b_count) cout << "TIE";
    else if (a_count > b_count) cout << "A";
    else cout << "B";

    return 0;
}