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

    // ����(�̹湮) �ε��� ����
    std::set<int> rem;
    for (int i = 0; i < N; ++i) rem.insert(i);

    // ���� ��� ť�� �ְ� ����
    q.push(start);
    visited[start] = 1;
    rem.erase(start);

    while (!q.empty()) {
        int i = q.front(); q.pop();
        long long L = x[i] - h[i];
        long long R = x[i] + h[i];

        // ��ǥ�� L �̻��� ù �ε���
        int idxLeft = int(std::lower_bound(x.begin(), x.end(), L) - x.begin());

        auto it = rem.lower_bound(idxLeft);
        // rem���� ���ǿ� �´� ��� �ε��� �����ϸ鼭 ť�� �߰�
        while (it != rem.end() && x[*it] <= R) {
            int j = *it;
            it = rem.erase(it); // C++11 �̻�: erase�� ���� iterator�� ��ȯ
            if (!visited[j]) {
                visited[j] = 1;
                q.push(j);
            }
        }
    }

    // ��� ���: �湮�� ���� ��ȣ(1-based) ��������
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
