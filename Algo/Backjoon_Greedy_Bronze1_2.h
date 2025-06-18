#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, K, sum = 0;
int a, b;
vector<pair<int, int>> v;

int main() {
    cin >> N >> L >> K;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        if (K == 0) break;

        if (L >= v[i].second) {
            sum += 140;
            K--;
        }
    }

    for (int i = 0; i < N; i++) {
        if (K == 0)
            break;

        if (L >= v[i].first && L < v[i].second) {
            sum += 100;
            K--;
        }
    }

    cout << sum;

    return 0;
}