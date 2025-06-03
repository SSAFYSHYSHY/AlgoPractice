#pragma once
#include <string>
#include <iostream>

using namespace std;

bool Calc(string s) {
    int a = 0, b = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'p' || s[i] == 'P') {
            a++;
        }
        else if (s[i] == 'y' || s[i] == 'Y') {
            b++;
        }
    }

    return a == b;
}

bool solution(string s)
{
    bool answer = true;

    if (!Calc(s)) {
        answer = false;
    }

    return answer;
}