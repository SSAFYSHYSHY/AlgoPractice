#pragma once
#include <iostream>
#include <deque>
#include <climits>
using namespace std;

long long t;
long long n;
long long A0, B0;
long long father[100001], mother[100001];
long long dist[100001];

void Input() {
    cin >> n;
    cin >> A0 >> B0;

    for (long long i = 1; i <= n; i++) {
        cin >> father[i] >> mother[i];
        dist[i] = LLONG_MAX; // 최소 여성 수 초기화
    }
}

void BFS() {
    deque<long long> dq;
    dist[A0] = 0;
    dq.push_front(A0);

    while (!dq.empty()) {
        long long curr = dq.front();
        dq.pop_front();

        if (curr == B0) break; // 목표 도달 시 종료

        // 아버지로 이동 (비용 0)
        long long f = father[curr];
        if (f > 0 && dist[f] > dist[curr]) {
            dist[f] = dist[curr];
            dq.push_front(f);
        }

        // 어머니로 이동 (비용 1)
        long long m = mother[curr];
        if (m > 0 && dist[m] > dist[curr] + 1) {
            dist[m] = dist[curr] + 1;
            dq.push_back(m);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        Input();
        BFS();

        if (dist[B0] == LLONG_MAX)
            cout << "no ancestor\n";
        else
            cout << dist[B0] << "\n";
    }
}