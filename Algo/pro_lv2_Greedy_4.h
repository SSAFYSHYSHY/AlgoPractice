#pragma once
#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.size();

    // 1. ���� ���� ���� Ƚ��
    for (char c : name) {
        answer += min(c - 'A', 'Z' - c + 1);
    }

    // 2. Ŀ�� �̵� �ּ� Ƚ�� ���
    int move = len - 1; // �׳� ������ ���� ���

    for (int i = 0; i < len; i++) {
        int next = i + 1;

        // ���ӵ� A ���� ã��
        while (next < len && name[next] == 'A') next++;

        // i���� �ڷ� ���ư��� next�� ���� ���
        move = min(move, i + i + len - next);
        // or ���� ����, next���� ���ٰ� �ٽ� ���ƿ��� ��쵵 ���Ե�
    }

    answer += move;
    return answer;
}