#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    int minVal = *min_element(arr.begin(), arr.end());

    bool removed = false;
    for (int i = 0; i < arr.size(); i++) {
        if (!removed && arr[i] == minVal) {
            removed = true;
            continue;
        }
        answer.push_back(arr[i]);
    }

    // 모두 제거되었을 경우
    if (answer.empty()) {
        answer.push_back(-1);
    }

    return answer;
}
