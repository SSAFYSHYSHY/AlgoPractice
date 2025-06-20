#pragma once
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    int cnt = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (v[i] < v[i + 1]) {
            continue;
        }

        if (v[i] < v[i + 1] + K) {
            v[i + 1] += K;
            ++cnt;
        }
        else {
            cnt = -1;
            break;
        }
    }

    cout << cnt << '\n';
}
