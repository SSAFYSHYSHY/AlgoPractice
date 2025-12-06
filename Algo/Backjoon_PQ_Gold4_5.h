#pragma once
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    set<pair<int, int>> s;
    map<int, int> m;

    int N, M;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int problem, level;
        cin >> problem >> level;
        // 난이도 기준으로 오름차순 정렬하기 위해 난이도를 앞으로
        s.insert({ level,problem });
        m[problem] = level;
    }

    cin >> M;

    while (M--) {
        string input;
        cin >> input;

        if (input == "recommend") {
            int order;
            cin >> order;
            if (order == 1) {
                auto it = s.rbegin(); // set 맨 뒤에 있는 문제
                cout << it->second << "\n";
            }
            else {
                auto it = s.begin(); // 가장 앞에 있는 문제
                cout << it->second << "\n";
            }
        }
        else if (input == "add") {
            int problem, level;
            cin >> problem >> level;
            s.insert({ level,problem });
            m[problem] = level;
        }
        else {
            int problem;
            cin >> problem;
            // 문제 번호를 키로 난이도를 구함
            s.erase({ m[problem],problem });
        }
    }
}