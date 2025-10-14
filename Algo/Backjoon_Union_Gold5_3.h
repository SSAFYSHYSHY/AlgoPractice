#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

struct Star {
    int x, y;
};

int parent[501];

// Union-Find �Լ�
int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int skyCount = 1;

    while (cin >> n, n != 0) {
        vector<Star> stars(n);
        for (int i = 0; i < n; i++) {
            cin >> stars[i].x >> stars[i].y;
            parent[i] = i; // �ʱ�ȭ
        }

        // �� ������ ���� ����� �� ã��
        for (int i = 0; i < n; i++) {
            double minDist = 1e9;
            vector<int> closest;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                double dist = (stars[i].x - stars[j].x) * 1.0 * (stars[i].x - stars[j].x) +
                    (stars[i].y - stars[j].y) * 1.0 * (stars[i].y - stars[j].y);
                if (dist < minDist - 1e-9) { // ���ο� �ּ� �Ÿ�
                    minDist = dist;
                    closest.clear();
                    closest.push_back(j);
                }
                else if (fabs(dist - minDist) < 1e-9) { // �ּ� �Ÿ��� ����
                    closest.push_back(j);
                }
            }
            // Union ó��
            for (int j : closest) {
                Union(i, j);
            }
        }

        set<int> constellations;
        for (int i = 0; i < n; i++) {
            constellations.insert(Find(i));
        }

        cout << "Sky " << skyCount++ << " contains "
            << constellations.size() << " constellations.\n";
    }

    return 0;
}
