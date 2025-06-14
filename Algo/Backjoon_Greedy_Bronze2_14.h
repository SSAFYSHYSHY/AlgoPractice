#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int x = 0, y = 0, q = 0;
        for (char ch : s) {
            if (ch == 'U') y++;
            else if (ch == 'D') y--;
            else if (ch == 'L') x--;
            else if (ch == 'R') x++;
            else if (ch == '?') q++;
        }
        int min_x = x - q;
        int max_x = x + q;
        int min_y = y - q;
        int max_y = y + q;
        cout << min_x << " " << min_y << " " << max_x << " " << max_y << '\n';
    }
    return 0;
}
