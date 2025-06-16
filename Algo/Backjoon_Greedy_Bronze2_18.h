#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> max_beauty(11, 0);

        for (int i = 0; i < n; ++i) {
            int b, d;
            cin >> b >> d;
            max_beauty[d] = max(max_beauty[d], b);
        }

        bool missing = false;
        int total = 0;
        for (int i = 1; i <= 10; ++i) {
            if (max_beauty[i] == 0) {
                missing = true;
                break;
            }
            total += max_beauty[i];
        }

        if (missing) cout << "MOREPROBLEMS" << endl;
        else cout << total << endl;
    }

    return 0;
}
