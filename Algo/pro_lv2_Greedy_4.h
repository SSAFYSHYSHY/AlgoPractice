#pragma once
#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.size();

    // 1. 문자 변경 조작 횟수
    for (char c : name) {
        answer += min(c - 'A', 'Z' - c + 1);
    }

    // 2. 커서 이동 최소 횟수 계산
    int move = len - 1; // 그냥 끝까지 가는 경우

    for (int i = 0; i < len; i++) {
        int next = i + 1;

        // 연속된 A 구간 찾기
        while (next < len && name[next] == 'A') next++;

        // i에서 뒤로 돌아가서 next로 가는 경우
        move = min(move, i + i + len - next);
        // or 왼쪽 먼저, next까지 갔다가 다시 돌아오는 경우도 포함됨
    }

    answer += move;
    return answer;
}