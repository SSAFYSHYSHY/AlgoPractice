#pragma once
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> map;

vector<int> solution(vector<int> numbers) {

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            int sum = numbers[i] + numbers[j];

            map.insert(sum);
        }
    }
    vector<int> answer(map.begin(), map.end());

    return answer;
}