#pragma once
#include <iostream>
using namespace std;

int parent[100001];
int sz[100001];

int u[200001], v[200001];

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    parent[b] = a;
    sz[a] += sz[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 1; i <= M; i++) {
        cin >> u[i] >> v[i];
    }

    // K��° ���� �����ϰ� ��� ��ġ��
    for (int i = 1; i <= M; i++) {
        if (i == K) continue;
        Union(u[i], v[i]);
    }

    // ������Ʈ ���� Ȯ��
    int rootCount = 0;
    for (int i = 1; i <= N; i++) {
        if (Find(i) == i) rootCount++;
    }

    if (rootCount == 1) {
        // ������ �ϳ��� ���� ������Ʈ��, ��� �ִܰŸ� = 0
        cout << 0 << "\n";
        return 0;
    }

    // �׷��� �ʴٸ� K��° �������� ���� �� ������ ũ�� ���
    int a = u[K];
    int b = v[K];
    int sizeA = sz[Find(a)];
    int sizeB = sz[Find(b)];

    long long ans = 1LL * sizeA * sizeB;
    cout << ans << "\n";

    return 0;
}