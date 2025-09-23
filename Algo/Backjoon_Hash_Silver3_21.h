#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>
#define MAX 100001
using namespace std;
typedef pair<int, int> pii;

struct pair_hash {
    size_t operator()(const pii& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) * 31);
    }
};

unordered_set<pii, pair_hash> s;
vector<pii> v;
int direct[4][2] = { {2,0},{0,2},{-2,0},{0,-2} };
int N, K;

void func() {
    int ret = 0;
    for (auto xy : v) {
        int x = xy.first;
        int y = xy.second;
        for (int d = 0; d < 4; d++) {
            int nx = x + direct[d][0];
            int ny = y + direct[d][1];

            if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
            if (s.find({ nx,ny }) != s.end()) continue;

            ret++;
            s.insert({ nx,ny });
        }
    }

    cout << ret << '\n';
}

void input() {
    int x, y;
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        v.push_back({ x,y });
        s.insert({ x,y });
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    input();
    func();

    return 0;
}
