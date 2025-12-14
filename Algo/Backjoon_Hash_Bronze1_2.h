#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<string, vector<string>> mp;

    for (int i = 0; i < n; i++) {
        int len;
        string title;
        cin >> len >> title;

        string note, melody = "";
        for (int j = 0; j < 7; j++) {
            cin >> note;
            melody += note;
        }

        string prefix = melody.substr(0, 3);
        mp[prefix].push_back(title);
    }

    for (int i = 0; i < m; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        string key = a + b + c;

        if (mp.count(key) == 0) {
            cout << "!\n";
        }
        else if (mp[key].size() == 1) {
            cout << mp[key][0] << "\n";
        }
        else {
            cout << "?\n";
        }
    }
}