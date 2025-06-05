#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {

        int start = commands[i][0], endi = commands[i][1], idx = commands[i][2];

        start--;
        endi--;
        idx--;

        vector<int> v;
        for (int j = start; j <= endi; j++) {
            v.push_back(array[j]);
        }

        sort(v.begin(), v.end());

        answer.push_back(v[idx]);
    }

    return answer;
}