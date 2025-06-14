#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n, P, Q;
        cin >> n >> P >> Q;

        vector<int> eggs(n);
        for (int i = 0; i < n; i++) {
            cin >> eggs[i];
        }

        sort(eggs.begin(), eggs.end());

        int count = 0;
        int weight_sum = 0;

        for (int i = 0; i < n; i++) {
            if (count < P && weight_sum + eggs[i] <= Q) {
                weight_sum += eggs[i];
                count++;
            }
            else {
                break;
            }
        }

        cout << "Case " << t << ": " << count << endl;
    }

    return 0;
}
