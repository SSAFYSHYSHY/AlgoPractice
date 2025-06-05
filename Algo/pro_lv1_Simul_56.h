#pragma once
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> map;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

    for (int i = 0; i < name.size(); i++) {
        map[name[i]] = yearning[i];
    }


    for (int i = 0; i < photo.size(); i++) {

        int sum = 0;
        for (int j = 0; j < photo[i].size(); j++) {
            if (map.find(photo[i][j]) != map.end()) {
                sum += map[photo[i][j]];
            }
        }

        answer.push_back(sum);
    }


    return answer;
}