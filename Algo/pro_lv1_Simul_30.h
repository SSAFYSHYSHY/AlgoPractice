#pragma once
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    // ù ��° ���ڴ� ������ ����
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

// �׽�Ʈ�� main �Լ�
int main() {
    vector<int> arr = { 1, 1, 3, 3, 0, 1, 1 };
    vector<int> result = solution(arr);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}