#pragma once
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a) {
        //�ݶ� a�� ������, ������ �Ǻ�.
        int num = n / a;
        int mod = n % a;

        //���信 num b�� ���ϱ�.
        answer += (num * b);

        //n �� �簻��.
        n = (num * b) + mod;

    }

    return answer;
}