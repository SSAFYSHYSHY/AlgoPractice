#pragma once
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> D(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> D[i];
    }

    vector<int> prefix2Count(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        prefix2Count[i] = prefix2Count[i - 1] + (D[i] == 2 ? 1 : 0);
    }

    vector<int> suffix1Count(N + 2, 0);
    for (int i = N; i >= 1; i--) {
        suffix1Count[i] = suffix1Count[i + 1] + (D[i] == 1 ? 1 : 0);
    }

    int answer = N;
    for (int i = 1; i <= N + 1; i++) {
        int changes = prefix2Count[i - 1] + suffix1Count[i];
        if (changes < answer) {
            answer = changes;
        }
    }

    cout << answer << '\n';

    return 0;
}
