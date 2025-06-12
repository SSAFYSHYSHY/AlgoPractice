#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int required = M - 1;
    int reward_cards = 0;
    vector<int> cost_to_fix;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        if (A >= N) {
            reward_cards++;
        }
        else {
            cost_to_fix.push_back(N - A);
        }
    }

    if (reward_cards >= required) {
        cout << 0 << '\n';
        return 0;
    }

    sort(cost_to_fix.begin(), cost_to_fix.end());

    int needed = required - reward_cards;
    int result = 0;
    for (int i = 0; i < needed; i++) {
        result += cost_to_fix[i];
    }

    cout << result << '\n';
    return 0;
}
