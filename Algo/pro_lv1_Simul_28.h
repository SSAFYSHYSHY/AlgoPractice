#pragma once
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    if (s.length() == 4 || s.length() == 6) {

        for (int i = 0; i < s.length(); i++) {
            if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z')) {
                return false;
            }
        }

        return true;
    }

    return false;
}