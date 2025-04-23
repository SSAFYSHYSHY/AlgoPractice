#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
        });
    int answer = 0;
    int last = -30001;

    for (int i = 0; i < routes.size(); i++) {
        int s = routes[i][0];
        int e = routes[i][1];

        if (last < s) {
            answer++;
            last = e;
        }
    }

    return answer;
}