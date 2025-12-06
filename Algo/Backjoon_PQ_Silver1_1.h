#pragma once
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> sushi[200001];
int eaten[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int k, a;
        cin >> k;
        while (k--) {
            cin >> a;
            sushi[a].push(i);
        }
    }

    while (m--) {
        int s;
        cin >> s;
        if (!sushi[s].empty()) {
            int g = sushi[s].front();
            sushi[s].pop();
            eaten[g]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << eaten[i] << " ";
    }
}