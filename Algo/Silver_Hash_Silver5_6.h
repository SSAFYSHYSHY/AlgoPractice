#pragma once
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<string, int> M;

    while (n--) {
        string s;
        cin >> s;
        if (s.size() >= 6 && s.substr(s.size() - 6, 6) == "Cheese")
            if (M.find(s) == M.end())
                M[s] = 1;
    }

    if (M.size() >= 4)
        cout << "yummy";
    else
        cout << "sad";
    return 0;
}