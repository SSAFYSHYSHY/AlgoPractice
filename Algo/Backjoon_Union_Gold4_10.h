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

    // K번째 간선 제외하고 모두 합치기
    for (int i = 1; i <= M; i++) {
        if (i == K) continue;
        Union(u[i], v[i]);
    }

    // 컴포넌트 개수 확인
    int rootCount = 0;
    for (int i = 1; i <= N; i++) {
        if (Find(i) == i) rootCount++;
    }

    if (rootCount == 1) {
        // 여전히 하나의 연결 컴포넌트면, 모든 최단거리 = 0
        cout << 0 << "\n";
        return 0;
    }

    // 그렇지 않다면 K번째 간선으로 나뉜 두 집합의 크기 계산
    int a = u[K];
    int b = v[K];
    int sizeA = sz[Find(a)];
    int sizeB = sz[Find(b)];

    long long ans = 1LL * sizeA * sizeB;
    cout << ans << "\n";

    return 0;
}