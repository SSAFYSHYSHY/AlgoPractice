#pragma once
#include <bits/stdc++.h>

using namespace std;

map<pair<string, string>, int> mp;

int main() {
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        string c, s;
        cin >> c >> s;

        c = c.substr(0, 2);

        if (s == c) continue;

        mp[{s, c}]++;

        ans += mp[{c, s}];
    }

    cout << ans << '\n';
    return 0;
}