#pragma once
#include <string>
#include <vector>


using namespace std;

int solution(string t, string p) {
    int answer = 0;

    long long num = stoll(p);
    for (int i = 0; i <= t.length() - p.length(); i++) {
        string s;
        for (int j = i; j < i + p.length(); j++) {
            s += t[j];
        }

        long long num2 = stoll(s);

        if (num >= num2) {
            answer++;
        }
    }

    return answer;
}