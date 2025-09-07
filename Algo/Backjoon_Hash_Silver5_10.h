#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;

    for (int tc = 1; tc <= c; tc++) {
        unordered_map<string, int> teams;

        for (int i = 0; i < 16; i++) {
            string t1, t2;
            int g1, g2;
            cin >> t1 >> t2 >> g1 >> g2;

            if (g1 > g2) teams[t1]++;
            else teams[t2]++;
        }

        string winner;
        for (auto i : teams) {
            if (i.second == 4) {
                winner = i.first;
            }
        }

        cout << winner << "\n";
    }
    return 0;
}
