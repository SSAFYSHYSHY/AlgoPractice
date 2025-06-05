#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.rbegin(), score.rend());

    for (int i = 0; i + m - 1 < score.size(); i += m) {
        int num = score[i + m - 1];
        answer += num * m;
    }

    return answer;
}