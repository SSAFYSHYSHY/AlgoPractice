#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;
unordered_map<int, pair<int, int>> mapv;
vector<map<pair<int, int>, int>> vv;
int answer;

void Calc(vector<int>& v) {
    pair<int, int> final;

    int t = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        pair<int, int>curr = mapv[v[i]];
        pair<int, int>next = mapv[v[i + 1]];
        final = next;

        while (curr != next) {
            vv[t][curr]++;
            if (vv[t][curr] == 2)answer++;
            int dy = curr.first - next.first;
            int dx = curr.second - next.second;

            if (dy != 0) {
                if (dy > 0)
                    curr.first--;
                else
                    curr.first++;
            }
            else if (dx != 0) {
                if (dx > 0)
                    curr.second--;
                else
                    curr.second++;
            }
            t++;
        }
    }

    vv[t][final]++;
    if (vv[t][final] == 2)answer++;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {

    for (int i = 0; i < points.size(); i++) {
        mapv[i + 1] = { points[i][0],points[i][1] };
    }
    vv.resize(100001);

    for (auto i : routes) {
        Calc(i);
    }

    return answer;
}