#pragma once
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a) {
        //콜라 a로 나누기, 나머지 판별.
        int num = n / a;
        int mod = n % a;

        //정답에 num b에 곱하기.
        answer += (num * b);

        //n 값 재갱신.
        n = (num * b) + mod;

    }

    return answer;
}