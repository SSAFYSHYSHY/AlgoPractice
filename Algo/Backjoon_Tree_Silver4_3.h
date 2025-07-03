#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
int parent[21]; // 각 노드의 부모
vector<int> people; // 테이블에 앉은 사람들

// 주어진 노드의 조상들을 set에 저장 (자신 포함)
set<int> getAncestors(int x) {
    set<int> s;
    while (true) {
        s.insert(x);
        if (x == 0) break; // 0은 루트 (Ida-Ottilia)
        x = parent[x];
    }
    return s;
}

// 두 노드의 공통 조상 중 가장 가까운 조상 반환
int findLCA(int a, int b) {
    set<int> ancestorsA = getAncestors(a);
    while (true) {
        if (ancestorsA.count(b)) return b;
        b = parent[b];
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> parent[i]; // 1~N번 후손의 부모 정보
    }

    people.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> people[i];
    }

    // 처음 두 명의 LCA를 찾고, 나머지 사람들과 차례로 LCA 갱신
    int lca = findLCA(people[0], people[1]);
    for (int i = 2; i < M; ++i) {
        lca = findLCA(lca, people[i]);
    }

    cout << lca << endl;

    return 0;
}
