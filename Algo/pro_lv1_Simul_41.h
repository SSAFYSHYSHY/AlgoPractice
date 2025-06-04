#pragma once
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string left = "";

    // ���� ������ 1������ ���� (0���� ��)
    for (int i = 1; i < food.size(); i++) {
        int repeat = food[i] / 2;  // ���� �������� �����ϰ� ���� �� �ִ� ������ŭ
        left += string(repeat, '0' + i);  // i�� ������ repeat�� ��ŭ �߰�
    }

    string right = left;  // ������ ������ ������ �ݴ� �������� ����
    reverse(right.begin(), right.end());  // �ݴ� ������ ������

    return left + "0" + right;  // ���� + �� + ����
}