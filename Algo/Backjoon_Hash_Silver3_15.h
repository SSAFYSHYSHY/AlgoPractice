#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);

        unordered_map<string, int> mp;
        stringstream ss1(line1);
        string token;
        while (getline(ss1, token, ',')) {
            int pos = token.find(':');
            string name = token.substr(0, pos);
            int cost = stoi(token.substr(pos + 1));
            mp[name] = cost;
        }

        int answer = 1e9;
        stringstream ss2(line2);
        while (getline(ss2, token, '|')) {
            stringstream ss3(token);
            string cond;
            int maxCost = 0;
            while (getline(ss3, cond, '&')) {
                maxCost = max(maxCost, mp[cond]);
            }
            answer = min(answer, maxCost);
        }

        cout << answer << "\n";
    }

    return 0;
}
