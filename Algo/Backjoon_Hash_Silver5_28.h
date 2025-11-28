#pragma once
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int C, P;
        cin >> C >> P;

        unordered_map<string, array<int, 3>> coffee;

        for (int i = 0; i < C; i++) {
            string name;
            int S, M, L;
            cin >> name >> S >> M >> L;
            coffee[name] = { S, M, L };
        }

        vector<pair<string, int>> result;
        result.reserve(P);

        int delivery = 100 / P;  // floor division

        for (int i = 0; i < P; i++) {
            string person, size, coffName;
            cin >> person >> size >> coffName;

            int price = 0;
            if (size == "small") price = coffee[coffName][0];
            else if (size == "medium") price = coffee[coffName][1];
            else price = coffee[coffName][2];

            int total = price + delivery;

            int r = total % 5;
            if (r == 1) total -= 1;
            else if (r == 4) total += 1;

            result.push_back({ person, total });
        }

        for (auto& p : result) {
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}