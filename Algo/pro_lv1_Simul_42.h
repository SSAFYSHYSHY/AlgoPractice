#pragma once
#include <string>
#include <vector>

using namespace std;

string arr[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int solution(string s) {
    string answer = "";
    string cpy;

    for (int i = 0; i < s.length(); i++) {

        if ('0' <= s[i] && s[i] <= '9') {
            answer += s[i];
            cpy = "";
        }
        else {
            cpy += s[i];

            for (int j = 0; j < 10; j++) {
                if (arr[j] == cpy) {
                    answer += to_string(j);
                    cpy = "";
                    break;
                }
            }

        }


    }



    return stoi(answer);
}