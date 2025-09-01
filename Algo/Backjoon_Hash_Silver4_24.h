#pragma once
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c; cin >> c;

    while (c--) {
        int n; cin >> n;
        unordered_map<string, int> um;
        int A[n];
        vector<string> v(n); for (int i = 0; i < n; i++) { cin >> v[i]; um[v[i]] = i; }

        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            A[i] = um[s];
        }

        string ans[n];
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            ans[A[i]] = s;
        }

        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}