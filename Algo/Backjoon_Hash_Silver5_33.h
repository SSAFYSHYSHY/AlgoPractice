#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<string, int> price;   // 상품명 → 가격
    vector<string> names;               // 상품명 리스트

    names.reserve(N);

    for (int i = 0; i < N; i++) {
        string name;
        int p;
        cin >> name >> p;
        price[name] = p;
        names.push_back(name);
    }

    int M;
    cin >> M;

    unordered_map<string, int> cnt;     // 상품명 → 등장 횟수
    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;
        cnt[name]++;
    }

    // 현재 총 비용 계산
    long long original = 0;
    for (auto& nm : names) {
        original += 1LL * cnt[nm] * price[nm];
    }

    long long best = original;

    // 모든 상품 쌍을 시도
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            const string& a = names[i];
            const string& b = names[j];

            long long pa = price[a];
            long long pb = price[b];
            long long ca = cnt[a];
            long long cb = cnt[b];

            // (a ↔ b) 가격 교환했을 때 변동량 계산
            long long diff =
                ca * (pb - pa) +
                cb * (pa - pb);

            long long new_sum = original + diff;

            if (new_sum < best)
                best = new_sum;
        }
    }

    cout << best << "\n";
    return 0;
}