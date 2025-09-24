#pragma once
#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>

using namespace std;

bool cmp(pair<int, float>& a, pair<int, float>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> temp;

    sort(stages.begin(), stages.end());
    int cnt = 0;

    int n = stages.size();
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 0; j < stages.size(); j++) {
            if (i == stages[j]) {
                cnt++;
            }
        }

        float avg = 0.0;
        if (n > 0) avg = (float)cnt / n;

        temp.push_back({ i,avg });
        n -= cnt;

    }
    sort(temp.begin(), temp.end(), cmp);

    for (int i = 0; i < temp.size(); i++) {
        answer.push_back(temp[i].first);
    }

    return answer;
}