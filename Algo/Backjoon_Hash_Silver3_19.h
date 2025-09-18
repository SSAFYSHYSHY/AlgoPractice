#pragma once
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<string>> characteristics;

int num_common(int i, int j) {
    int count = 0;
    vector<string>& v1 = characteristics[i];
    vector<string>& v2 = characteristics[j];

    for (auto& trait1 : v1) {
        for (auto& trait2 : v2) {
            if (trait1 == trait2) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    characteristics.assign(N, {});

    for (int i = 0; i < N; i++) {
        string name;
        int K;
        cin >> name >> K;  // 동물 이름, 특성 개수
        characteristics[i].resize(K);
        for (int j = 0; j < K; j++) {
            cin >> characteristics[i][j]; // 특성 저장
        }
    }

    int largest = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            largest = max(largest, num_common(i, j));
        }
    }

    cout << largest + 1 << "\n";
    return 0;
}
