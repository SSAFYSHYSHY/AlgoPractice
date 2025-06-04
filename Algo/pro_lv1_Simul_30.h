#pragma once
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    // 첫 번째 숫자는 무조건 포함
    if (!arr.empty()) {
        answer.push_back(arr[0]);
    }

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i - 1]) {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}

// 테스트용 main 함수
int main() {
    vector<int> arr = { 1, 1, 3, 3, 0, 1, 1 };
    vector<int> result = solution(arr);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}