#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    int n;
    cin >> n;

    vector<int> v;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        mp[num]++;
    }

    sort(v.begin(), v.end());

    // Æò±Õ
    double sum = 0;
    for (int x : v) sum += x;
    cout << (int)round(sum / n) << "\n";

    // Áß¾Ó°ª
    cout << v[n / 2] << "\n";

    // ÃÖºó°ª
    vector<pair<int, int>> v2;
    for (auto& p : mp)
        v2.push_back(p);

    sort(v2.begin(), v2.end(), cmp);

    int maxFreq = v2[0].second;
    vector<int> modes;
    for (auto& p : v2)
        if (p.second == maxFreq)
            modes.push_back(p.first);

    if (modes.size() == 1)
        cout << modes[0] << "\n";
    else
        cout << modes[1] << "\n";

    // ¹üÀ§
    cout << v.back() - v.front() << "\n";
}