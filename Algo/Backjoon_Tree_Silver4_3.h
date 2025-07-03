#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
int parent[21]; // �� ����� �θ�
vector<int> people; // ���̺� ���� �����

// �־��� ����� ������� set�� ���� (�ڽ� ����)
set<int> getAncestors(int x) {
    set<int> s;
    while (true) {
        s.insert(x);
        if (x == 0) break; // 0�� ��Ʈ (Ida-Ottilia)
        x = parent[x];
    }
    return s;
}

// �� ����� ���� ���� �� ���� ����� ���� ��ȯ
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
        cin >> parent[i]; // 1~N�� �ļ��� �θ� ����
    }

    people.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> people[i];
    }

    // ó�� �� ���� LCA�� ã��, ������ ������ ���ʷ� LCA ����
    int lca = findLCA(people[0], people[1]);
    for (int i = 2; i < M; ++i) {
        lca = findLCA(lca, people[i]);
    }

    cout << lca << endl;

    return 0;
}
