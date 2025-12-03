#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

struct Product {
    int points;
    int days;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        unordered_map<string, Product> table;
        table.reserve(N);

        // 제품 정보 입력
        for (int i = 0; i < N; i++) {
            string name;
            int p, d;
            cin >> name >> p >> d;
            table[name] = { p, d };
        }

        int C;
        cin >> C;

        int discontent = 0;   // 불만족 고객 수

        while (C--) {
            int custNo, P, M;
            cin >> custNo >> P >> M;

            int total = 0;
            bool unhappy = false;

            for (int i = 0; i < P; i++) {
                string item;
                cin >> item;

                auto& prod = table[item];

                // 배송일이 허용 범위 내인지 확인
                if (prod.days <= M) {
                    total += prod.points;
                }
                else {
                    unhappy = true;
                }
            }

            // 출력
            if (unhappy) discontent++;

            cout << custNo << " " << total;
            if (unhappy) cout << " *";
            cout << "\n";
        }

        cout << "Number of discontented customers is: "
            << discontent << "\n";
    }

    return 0;
}