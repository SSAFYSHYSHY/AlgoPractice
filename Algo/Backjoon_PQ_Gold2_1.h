#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> gems(N);
    vector<int> bags(K);

    for (int i = 0; i < N; i++) {
        cin >> gems[i].first >> gems[i].second;
    }
    for (int i = 0; i < K; i++) {
        cin >> bags[i];
    }

    sort(gems.begin(), gems.end());
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;
    long long sum = 0;
    int idx = 0;

    for (int i = 0; i < K; i++) {
        while (idx < N && gems[idx].first <= bags[i]) {
            pq.push(gems[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;
    return 0;
}