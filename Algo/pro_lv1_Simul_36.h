#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    int idx = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            answer += ' ';
            idx = 0;
        }

        if (idx % 2 == 0 && s[i] != ' ') {
            answer += toupper(s[i]);
            idx++;
        }
        else if (idx % 2 == 1 && s[i] != ' ') {
            answer += tolower(s[i]);
            idx++;
        }
    }

    return answer;
}