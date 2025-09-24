#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, pair<char, int>> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num, dist;
        char dir;
        cin >> num >> dir >> dist;
        m[num] = { dir, dist }; // insert 대신 대입 (덮어쓰기 허용)
    }

    int now;
    cin >> now;

    for (int i = 0; i < n; i++) {
        if (m.find(now) == m.end()) { // 안전성 체크
            cerr << "Error: undefined key " << now << "\n";
            break;
        }

        char dir = m[now].first;
        int dist = m[now].second;

        if (dir == 'R') now += dist;
        else now -= dist;
    }

    cout << now << "\n";
    return 0;
}
