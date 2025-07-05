#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore();  // 개행 처리

    while (T--) {
        int numPrize, numSticker;
        string line;
        getline(cin, line);
        stringstream ss(line);
        ss >> numPrize >> numSticker;

        vector<vector<int>> prizes(numPrize);
        for (int i = 0; i < numPrize; ++i) {
            getline(cin, line);
            stringstream ss2(line);

            int cnt;
            ss2 >> cnt;
            prizes[i].resize(cnt + 2);
            prizes[i][0] = cnt;
            for (int j = 1; j <= cnt + 1; ++j) {
                ss2 >> prizes[i][j];
            }
        }

        getline(cin, line);
        stringstream ss3(line);
        vector<int> stickers(numSticker + 1);
        for (int i = 0; i < numSticker; ++i) {
            ss3 >> stickers[i];
        }

        int result = 0;
        for (int i = 0; i < numPrize; ++i) {
            int minVal = 987654321;
            int count = prizes[i][0];
            for (int j = 1; j <= count; ++j) {
                int idx = prizes[i][j] - 1;
                minVal = min(minVal, stickers[idx]);
            }
            result += prizes[i][count + 1] * minVal;
        }

        cout << result << '\n';
    }

    return 0;
}
