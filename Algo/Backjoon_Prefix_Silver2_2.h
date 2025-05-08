#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

int timeline[202];

int main() {
    int test;
    cin >> test;

    while (test--) {
        fill(timeline, timeline + 202, 0);

        int num;
        cin >> num;

        for (int i = 0; i < num; i++) {
            int start, end;
            cin >> start >> end;

            if (start > end) swap(start, end);

            start = (start - 1) / 2;
            end = (end - 1) / 2;

            timeline[start]++;
            timeline[end + 1]--;
        }

        int result = 0, curr = 0;
        for (int i = 0; i < 201; i++) {
            curr += timeline[i];
            result = max(result, curr);
        }

        cout << result * 10 << '\n';
    }

    return 0;
}
