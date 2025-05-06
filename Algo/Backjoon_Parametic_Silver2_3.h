#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEnough(long long time, const vector<int>& burners, int n) {
    long long total = 0;
    for (int t : burners) {
        total += time / t;
        if (total >= n) return true;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> burners(k);

    for (int i = 0; i < k; ++i) {
        cin >> burners[i];
    }

    long long left = 1;
    long long right = 1LL * *min_element(burners.begin(), burners.end()) * n;
    long long answer = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (isEnough(mid, burners, n)) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";
    return 0;
}
