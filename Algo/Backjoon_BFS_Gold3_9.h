#pragma once
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    if (!(cin >> N >> S)) return 0;

    vector<long long> x(N);
    for (int i = 0; i < N; ++i) cin >> x[i];

    vector<long long> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    int start = S - 1; // 0-based index

    vector<char> visited(N, 0);
    queue<int> q;

    // 남은(미방문) 인덱스 집합
    std::set<int> rem;
    for (int i = 0; i < N; ++i) rem.insert(i);

    // 시작 노드 큐에 넣고 제거
    q.push(start);
    visited[start] = 1;
    rem.erase(start);

    while (!q.empty()) {
        int i = q.front(); q.pop();
        long long L = x[i] - h[i];
        long long R = x[i] + h[i];

        // 좌표값 L 이상인 첫 인덱스
        int idxLeft = int(std::lower_bound(x.begin(), x.end(), L) - x.begin());

        auto it = rem.lower_bound(idxLeft);
        // rem에서 조건에 맞는 모든 인덱스 제거하면서 큐에 추가
        while (it != rem.end() && x[*it] <= R) {
            int j = *it;
            it = rem.erase(it); // C++11 이상: erase는 다음 iterator를 반환
            if (!visited[j]) {
                visited[j] = 1;
                q.push(j);
            }
        }
    }

    // 결과 출력: 방문된 차량 번호(1-based) 오름차순
    bool first = true;
    for (int i = 0; i < N; ++i) {
        if (visited[i]) {
            if (!first) cout << ' ';
            first = false;
            cout << (i + 1);
        }
    }
    cout << '\n';
    return 0;
}
