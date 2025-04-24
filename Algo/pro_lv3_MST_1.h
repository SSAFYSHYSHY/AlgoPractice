#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

int Calc(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Calc(parent[x]);
}

void Union(int a, int b) {
    a = Calc(a);
    b = Calc(b);
    if (a != b) parent[b] = a;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
        });

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < costs.size(); i++) {
        int a = costs[i][0];
        int b = costs[i][1];
        int cost = costs[i][2];

        if (Calc(a) != Calc(b)) {
            Union(a, b);
            answer += cost;
        }

    }

    return answer;
}