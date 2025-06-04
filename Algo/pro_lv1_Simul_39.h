#pragma once
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            answer += ' ';
        }
        else if ('A' <= s[i] && s[i] <= 'Z') {
            answer += (s[i] - 'A' + n) % 26 + 'A';
        }
        else if ('a' <= s[i] && s[i] <= 'z') {
            answer += (s[i] - 'a' + n) % 26 + 'a';
        }
    }

    return answer;
}