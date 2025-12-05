#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool used[50];   // 각 시간 슬롯 참석 여부 체크

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int day = 1; ; day++) {
        memset(used, false, sizeof(used));

        int P;          // 파티 개수
        cin >> P;
        if (P == 0) break;

        vector<pair<int, pair<int, int>>> parties;
        // (duration, {start*2, end*2})

        for (int i = 0; i < P; i++) {
            int start, end;
            cin >> start >> end;
            if (start == end) continue;  // duration 0은 참석 불가

            parties.push_back({ end - start, {start * 2, end * 2} });
        }

        // 가장 짧은 파티부터 정렬 (그리디)
        sort(parties.begin(), parties.end());

        int count = 0;

        for (auto& party : parties) {
            int s = party.second.first;
            int e = party.second.second;

            // 가능한 시간 슬롯 하나만 잡으면 OK
            for (int time = s; time < e; time++) {
                if (!used[time]) {
                    used[time] = true;
                    count++;
                    break;
                }
            }
        }

        cout << "On day " << day
            << " Emma can attend as many as "
            << count << " parties.\n";
    }

    return 0;
}