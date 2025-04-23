#pragma once
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for (int i = 0; i < prices.size(); i++) {
        int cnt = 0;

        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[i] <= prices[j]) {
                cnt++;
            }
            else {
                cnt++;
                break;
            }

        }

        answer.push_back(cnt);
    }

    return answer;
}