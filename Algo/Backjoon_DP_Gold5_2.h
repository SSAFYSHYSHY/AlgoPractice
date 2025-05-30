#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(3), v(3), v2(3);

    // 초기 입력
    cin >> v[0] >> v[1] >> v[2];
    v2 = v;

    for (int i = 1; i < n; ++i) {
        cin >> arr[0] >> arr[1] >> arr[2];

        int prevMax0 = v[0], prevMax1 = v[1], prevMax2 = v[2];
        v[0] = max(prevMax0, prevMax1) + arr[0];
        v[1] = max({ prevMax0, prevMax1, prevMax2 }) + arr[1];
        v[2] = max(prevMax1, prevMax2) + arr[2];

        int prevMin0 = v2[0], prevMin1 = v2[1], prevMin2 = v2[2];
        v2[0] = min(prevMin0, prevMin1) + arr[0];
        v2[1] = min({ prevMin0, prevMin1, prevMin2 }) + arr[1];
        v2[2] = min(prevMin1, prevMin2) + arr[2];
    }

    cout << *max_element(v.begin(), v.end()) << " ";
    cout << *min_element(v2.begin(), v2.end()) << "\n";

    return 0;
}