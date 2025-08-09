#pragma once
//2Áß ¹è¿­ prefix
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int tc = 1; tc <= N; tc++) {
        int L, W;
        cin >> L >> W;
        vector<vector<int>> grid(W + 1, vector<int>(L + 1, 0));
        vector<vector<int>> prefix(W + 1, vector<int>(L + 1, 0));

        for (int y = 1; y <= W; y++) {
            string row;
            cin >> row;
            for (int x = 1; x <= L; x++) {
                char c = row[x - 1];
                grid[y][x] = (c == 'G' || c == 'S') ? 1 : 0;
            }
        }

        for (int y = 1; y <= W; y++) {
            for (int x = 1; x <= L; x++) {
                prefix[y][x] = grid[y][x]
                    + prefix[y - 1][x]
                    + prefix[y][x - 1]
                    - prefix[y - 1][x - 1];
            }
        }

        auto rect_sum = [&](int y1, int x1, int y2, int x2) {
            return prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1];
            };

        int ans = 0;
        for (int y1 = 1; y1 <= W; y1++) {
            for (int x1 = 1; x1 <= L; x1++) {
                for (int y2 = y1; y2 <= W; y2++) {
                    for (int x2 = x1; x2 <= L; x2++) {
                        int area = (y2 - y1 + 1) * (x2 - x1 + 1);
                        if (rect_sum(y1, x1, y2, x2) == area) {
                            ans = max(ans, area);
                        }
                    }
                }
            }
        }

        cout << "Case #" << tc << ": " << ans << "\n";
    }
}
