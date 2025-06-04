#pragma once
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string left = "";

    // 음식 종류는 1번부터 시작 (0번은 물)
    for (int i = 1; i < food.size(); i++) {
        int repeat = food[i] / 2;  // 양쪽 선수에게 공평하게 나눌 수 있는 개수만큼
        left += string(repeat, '0' + i);  // i번 음식을 repeat개 만큼 추가
    }

    string right = left;  // 오른쪽 선수는 좌측의 반대 방향으로 먹음
    reverse(right.begin(), right.end());  // 반대 순서로 뒤집음

    return left + "0" + right;  // 좌측 + 물 + 우측
}